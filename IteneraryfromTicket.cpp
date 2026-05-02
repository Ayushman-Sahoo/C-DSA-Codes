#include <iostream> 
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void printItinerary(unordered_map<string, string> tickets) {

    // Starting Point
    unordered_set<string> to;

    for(pair<string, string> ticket : tickets) { // <from, to>
        to.insert(ticket.second);
    }

    string start = "";
    for(pair<string, string> ticket : tickets) {
        if(to.find(ticket.first) == to.end()) { // starting pt
            start = ticket.first;
        }
    }

    // Print the itinerary
    string current = start;
    while(tickets.find(current) != tickets.end()) {
        cout << current << " -> ";
        current = tickets[current];
    }
    cout << current << endl;

}

int main(){
    unordered_map<string, string> tickets;

    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";
    printItinerary(tickets);

    return 0;
}