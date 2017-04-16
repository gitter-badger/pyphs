/*
    Copyright or (c) or Copr. Project-Team S3 (Sound Signals and Systems) and
    Analysis/Synthesis team, Laboratory of Sciences and Technologies of Music and
    Sound (UMR 9912), IRCAM-CNRS-UPMC, 1 place Igor Stravinsky, F-75004 Paris
    * contributors : Antoine Falaize, Thomas Helie,
    * corresponding contributor: antoine.falaize@ircam.fr
    * date: 2016/12/31 12:47:34

    This has been geerated by PyPHS which purpose is to generate C++
    code for the simulation of multiphysics system described by graph structures.

    This software is governed by the CeCILL-B license under French law and
    abiding by the rules of distribution of free software.  You can  use,
    modify and/ or redistribute the software under the terms of the CeCILL-B
    license as circulated by CEA, CNRS and INRIA at the following URL
    "http://www.cecill.info".

    As a counterpart to the access to the source code and  rights to copy,
    modify and redistribute granted by the license, users are provided only
    with a limited warranty  and the software's author,  the holder of the
    economic rights, and the successive licensors  have only  limited liability.

    In this respect, the user's attention is drawn to the risks associated
    with loading,  using,  modifying and/or developing or reproducing the
    software by the user in light of its specific status of free software,
    that may mean  that it is complicated to manipulate,  and  that  also
    therefore means  that it is reserved for developers  and  experienced
    professionals having in-depth computer knowledge. Users are therefore
    encouraged to load and test the software's suitability as regards their
    requirements in conditions enabling the security of their systems and/or
    data to be ensured and,  more generally, to use and operate it in the
    same conditions as regards security.

    The fact that you are presently reading this means that you have had
    knowledge of the CeCILL-B license and that you accept its terms.

    Created on 2016/12/31 12:47:34

    author: Antoine Falaize


===========================================================================

    This file was automatically generated by PyPHS, date 2017/04/16 12:14:19.

    It contains the code for the simulation of system 'CORE'.

===========================================================================
*/


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdio>
#include <time.h>
#include <math.h>

#include "core.h"

using namespace std;

class timer {
private:
    unsigned long begTime;
public:
    void start() {
        begTime = clock();
    }
    unsigned long elapsedTime() {
        return ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
    }
    bool isTimeout(unsigned long seconds) {
        return seconds >= elapsedTime();
    }
};


int main() {    
    const unsigned int nt = 96000;
    
    vector<double> x0Vector(12);
    vector<double> uVector(1);
    vector<double> pVector(0);
    
    vector<double> xVector(12);
    vector<double> dxVector(12);
    vector<double> dxHVector(12);
    vector<double> wVector(0);
    vector<double> zVector(0);
    vector<double> yVector(1);

    ifstream x0File;
    x0File.open("/Users/Falaize/Documents/DEV/python/pyphs/pyphs/tutorials/data/x0.txt");

    if (x0File.fail()) {
        cerr << "Failed opening x0 file" << endl;
        exit(1);}
    ifstream uFile;
    uFile.open("/Users/Falaize/Documents/DEV/python/pyphs/pyphs/tutorials/data/u.txt");

    if (uFile.fail()) {
        cerr << "Failed opening u file" << endl;
        exit(1);}
    ifstream pFile;
    pFile.open("/Users/Falaize/Documents/DEV/python/pyphs/pyphs/tutorials/data/p.txt");

    if (pFile.fail()) {
        cerr << "Failed opening p file" << endl;
        exit(1);}

    // Get state initialization data
    for (unsigned int i=0; i<12; i++) {
        x0File >> x0Vector[i];
    }

    // Instance of PyPHS numerical core
    CORE core(x0Vector);

    int barWidth = 20;
    int ETA, ETAm, ETAs;
    float progress = 0.0;
    timer t;

    // Process
    t.start();

    ofstream xFile;
    xFile.open("/Users/Falaize/Documents/DEV/python/pyphs/pyphs/tutorials/data/x.txt");
    ofstream dxFile;
    dxFile.open("/Users/Falaize/Documents/DEV/python/pyphs/pyphs/tutorials/data/dx.txt");
    ofstream dxHFile;
    dxHFile.open("/Users/Falaize/Documents/DEV/python/pyphs/pyphs/tutorials/data/dxH.txt");
    ofstream wFile;
    wFile.open("/Users/Falaize/Documents/DEV/python/pyphs/pyphs/tutorials/data/w.txt");
    ofstream zFile;
    zFile.open("/Users/Falaize/Documents/DEV/python/pyphs/pyphs/tutorials/data/z.txt");
    ofstream yFile;
    yFile.open("/Users/Falaize/Documents/DEV/python/pyphs/pyphs/tutorials/data/y.txt");


    for (unsigned int n = 0; n < nt; n++) {


        // Get input data
        for (unsigned int i=0; i<1; i++) {
            uFile >> uVector[i];
        }
        std::cout << "[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) std::cout << "=";
            else if (i == pos) std::cout << ">";
            else std::cout << " ";
        }
        progress = float(n)/float(nt);
        if(1){
            ETA = (float(nt)/float(n+1)-1.)*(t.elapsedTime());
            ETAm = int(floor(ETA))/60;
            ETAs = floor(ETA%60);
            std::cout << "] " << int(progress * 100.0) << "% done, ETA: " << ETAm << "m" << ETAs << "s\r" << endl ;
            std::cout.flush();
        }

        // Process update
        core.update(uVector, pVector);

        // Get quantities        
        
        xVector = core.x_vector();
        for (unsigned int i = 0; i<12; i++){
            xFile << xVector[i] << " ";
        }
        xFile << endl;
        
        
        dxVector = core.dx_vector();
        for (unsigned int i = 0; i<12; i++){
            dxFile << dxVector[i] << " ";
        }
        dxFile << endl;
        
        
        dxHVector = core.dxH_vector();
        for (unsigned int i = 0; i<12; i++){
            dxHFile << dxHVector[i] << " ";
        }
        dxHFile << endl;
        
        
        wVector = core.w_vector();
        for (unsigned int i = 0; i<0; i++){
            wFile << wVector[i] << " ";
        }
        wFile << endl;
        
        
        zVector = core.z_vector();
        for (unsigned int i = 0; i<0; i++){
            zFile << zVector[i] << " ";
        }
        zFile << endl;
        
        
        yVector = core.y_vector();
        for (unsigned int i = 0; i<1; i++){
            yFile << yVector[i] << " ";
        }
        yFile << endl;
        
    }
    uFile.close();
    pFile.close();    
    xFile.close();
    dxFile.close();
    dxHFile.close();
    wFile.close();
    zFile.close();
    yFile.close();
    cout << endl;
    cout << "Data written at" << endl;
    cout << endl;
    cout << "/Users/Falaize/Documents/DEV/python/pyphs/pyphs/tutorials/data/"<< endl;
    cout << endl;

    return 0;
}