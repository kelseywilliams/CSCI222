//
// Created by Kelsey Williams on 2/27/2024.
//
#include "Railroad.h"
// Railroad constructer.
// Instatiate instance variables and create and populate rail
Railroad::Railroad(int rounds, int TRAIN_NUM, int TRACK_LEN, int TRACKS){
    this->rounds = rounds;
    this->TRAIN_NUM = TRAIN_NUM;
    this->TRACK_LEN = TRACK_LEN;
    this->TRACKS = TRACKS;
    this->assembleRail();
    this->populateTrains();
    this->toString(-1);
}
int Railroad::randgen(int start, int stop){
    return rand() % (stop - start + 1) + start;
}
void Railroad::crash(){
    std::cerr << "Error: Collision imminent. Halting system." << std::endl;
    exit(1);
}
// Assemble the railroad
void Railroad::assembleRail(){
    // Set length of rail vector
    this->rail.resize(this->TRACKS);
    // Assemble two tracks
    for(int i = 0; i < this->TRACKS; i++) {
        // Set current index on track with j
        int j = 0;
        // Create the first segment on the track and set its index to its current index
        auto head = new Segment();
        // If we are creating any track after the first, link parallel to previous track
        if (i > 0){
            head->lnk = this->rail[i - 1][j];
            this->rail[i - 1][j]->lnk = head;
        }
        // Push new segment to the rail
        this->rail[i].push_back(head);
        // Creat the rest of the segments in the track
        for (j = 1; j < this->TRACK_LEN; j++) {
            auto seg = new Segment();
            seg->index = j;
            seg->last = head;
            head->next = seg;
            head = seg;
            // If we are on the last segment of the track set tail = head
            if (j + 1 == this->TRACK_LEN) {
                head->next = this->rail[i][0];
                this->rail[i][0]->last = head;
            }
            // Any track created after the first will be linked parallel to the previous track
            if (i > 0){
                seg->lnk = this->rail[i - 1][j];
                this->rail[i - 1][j]->lnk = seg;
            }
            // Push the new segment onto the track
            this->rail[i].push_back(seg);
        }
    }
}
// Creates 4 trains at radom positions on the tracks
void Railroad::populateTrains(){
    Segment* seg;
    int i = 0;
    while(i < this->TRAIN_NUM){
        int track = i % 2;
        int pos = randgen(0, TRACK_LEN - 1);
        int train = randgen(0, 1) > 0 ? 1 : -1;
        int id = randgen(111, 999);
        seg = this->rail[track][pos];

        // If the segment does not currently hold a train, place a train in the segment
        if (seg->train == 0) {
            seg->train = train;
            seg->id = id;
            this->trains[id] = false;
            i++;
        }

    }
}
// Switch tracks of a train at a specified segment
void Railroad::swtch(Segment* seg) {
    // Get the segment that is the adjacent segment of the segment the
    // current train is heading towards
    Segment *next_adj_seg = seg->train > 0 ? seg->lnk->next : seg->lnk->last;
    int id = seg->id;

    // If the next adjacent segment has a train that is is oncoming, signal crash
    if (next_adj_seg->train != 0 && next_adj_seg->train != seg->train) {
        Railroad::crash();
    }

    // if the train has not been moved
    if (!(this->trains[seg->id])) {
        // If the adjacent segment contains a train
        if (seg->lnk->train != 0) {
            // If the adjacent segment contains a train that has not been moved
            // move the train at the segment
            if (!(this->trains[seg->lnk->id])) {
                this->move(seg->lnk);
            }
            // If the train has been moved, signal a crash
            else {
                this->crash();
            }
        }
        // Switch the tracks of the current train and signal it as moved
        seg->lnk->train = seg->train;
        seg->lnk->id = seg->id;
        seg->train = 0;
        seg->id = -1;

        this->trains[id] = true;
    }
    // If the current train has already been moved this round, signal a crash.
    else {
        Railroad::crash();
    }
}
// Move a train at a segment
void Railroad::move(Segment* seg){
    // Find the segment the train is heading towards
    Segment* next_seg = seg->train > 0 ? seg->next : seg->last;
    int id = seg->id;
    // If the next segment is empty and the train has not been moved
    // this round, advance the train to the next segment
    if (next_seg->train == 0 && !(this->trains[id])) {
        next_seg->train = seg->train;
        next_seg->id = id;
        seg->train = 0;
        seg->id = -1;

        // Set the value of the trains list to true at the ID of the train
        // to indicate that the train with that ID has been moved this round
        // and should not be moved again until the next round.
        this->trains[id] = true;
    }
    // If the next segment has a train, but it has not been moved this round
    // and is going the same direction as the current train, advance the
    // train in front, and then advance the current train
    else if (next_seg->train == seg->train && !(this->trains[id])){
        this->move(next_seg);
        this->move(seg);
    }
    // If there is an oncoming train, switch tracks
    else{
        this->swtch(seg);
    }
}
// Crawl rail looking for trains to move
void Railroad::crawlRail() {
    // Loop through both tracks on the rail
    for(int i = 0; i < this->TRACKS; i++){
        // Loop through the segments in the track
        for(int j = 0; j < this->TRACK_LEN; j++){
            // Get the current segment and relevant data
            Segment* seg = this->rail[i][j];
            int train = seg->train;
            int id = seg->id;

            // If the segment contains a train that has not been moved,
            // move the train in the segment
            if (train != 0 && !(this->trains[id])) {
                move(seg);
            }
        }
    }
    // When all the trains have been moved, every element {train id (int): moved (bool)}
    // in the train list will be set to true.
    // Reset all values in trains to false and exit the function.
    if (std::all_of(this->trains.begin(), this->trains.end(), [](const auto& pair) {
        return pair.second == true;
    })) {
        for (auto& pair : this->trains)
            pair.second = false;
        return;
    }
}
// Begin crawling the rail
void Railroad::start(){
    for (int i = 0; i < this->rounds; i++){
        this->crawlRail();
        this->toString(i);
    }
}
// Returns the appropriate train character given a segment off it's index.
std::string Railroad::trainChar(Segment* seg) {
    std::string output;
    if (seg->train < 0) output = seg->index < 5 ? "<" : ">";
    else if (seg->train > 0) output = seg->index < 5 ? ">" : "<";
    else if (seg->train == 0) output = "-";

    return output;
}
// Set to output with 4 trains, 10 segments and 2 tracks
void Railroad::toString(int round){
    std::string output;
    std::ostringstream stream;

    /* TRACK DIAGRAM: i = inner o = outer
    * +--  o0 - o1 - o2 - o3 - o4  --+ // top outer
    * | +- i0 - i1 - i2 - i3 - i4 -+ | // top inner
    * | |                          | |
    * | +- i9 - i8 - i7 - i6 - i5 -+ | // bottom inner
    * +--  o9 - o8 - o7 - o6 - o5  --+ // bottom outer
    */

    stream << round << ":" << std::endl;
    // Print top outer track
    stream << "+--";
    for (int i = 0; i < 5; i++) stream << Railroad::trainChar(this->rail[1][i]) << "--";
    stream << "+" << std::endl;

    // Print top divider
    stream << "|  ";
    for (int i = 0; i < 5; i++) stream << "x  ";
    stream << "|" << std::endl;

    // Print top inner track
    stream << "| ";
    for (int i = 0; i < 5; i++) stream << "-" << Railroad::trainChar(this->rail[0][i]) << "-";
    stream << " |" << std::endl;

    // Print middle
    stream << "| |";
    for (int i = 0; i < 13; i++) stream << " ";
    stream << "| |" << std::endl;

    // Print bottom inner track
    stream << "| ";
    for (int i = 9; i > 4; i--) stream << "-" << Railroad::trainChar(this->rail[0][i]) << "-";
    stream << " |" << std::endl;

    // Print bottom divider
    stream << "|  ";
    for (int i = 0; i < 5; i++) stream << "x  ";
    stream << "|\n";

    // Print Bottom outer track
    //
    stream << "+--";
    for (int i = 9; i > 4; i--) stream << Railroad::trainChar(this->rail[1][i]) << "--";
    stream << "+\n";

    output = stream.str();
    std::cout << output << std::endl;
}