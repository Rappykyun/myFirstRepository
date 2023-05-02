#include <iostream>
#include <fstream>
using namespace std;

void maxPoints(int points[][2], int noRabbits, ofstream& outfile) {
    int maxi = 2;
    bool hasSlope = false;
    for(int i=0; i<noRabbits; i++) {
        for(int j=i+1; j<noRabbits; j++) {
            int count=2;
            for(int k=0; k<noRabbits; k++) {
                if(k!=i && k!=j) {
                    //rabbit 1 and 2                                                rabbit 1 and 6
                    if((points[j][1]-points[i][1])*(points[i][0]-points[k][0])==(points[i][1]-points[k][1])*(points[j][0]-points[i][0])) {
                        count++;
                        hasSlope = true;
                    }
                }
            }
            maxi = max(maxi,count);
        }
    }
    if (hasSlope) {
        outfile<<"The total number of rabbits lies in a same line are: "<<maxi;
    } else {
        outfile<<"No points have the same slope.";
    }
    return;
}

int main() {
    int noRabbits;
    ifstream infile("inn.txt");
    ofstream outfile("outt.txt");
    infile >> noRabbits;
    int points[noRabbits][2];
    for(int i=0; i<noRabbits; i++) {
                infile >> points[i][0] >> points[i][1];
    }
    maxPoints(points,noRabbits,outfile);
    infile.close();
    outfile.close();
    return 0;
}
