#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "Customer.h"
#include "FirstModel.h"
#include "SecondModel.h"

using namespace std;

template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
        return 1;
    }

 //   cout << "input file: " << argv[1] << endl;
 //   cout << "output file: " << argv[2] << endl;

    ifstream infile(argv[1]);
    string line;
    getline(infile, line);
    //cout<<"line 1: "<<line<<endl;
    int N = stoi(line);
    getline(infile, line);
    //cout<<"line 2:"<<line<<endl;
    int M = stoi(line);
    //cout << "number of N: " << N << endl;
    //cout << "number of input lines: " << M << endl;
    vector<Customer> input(M);

    for(int i=0; i<M; i++){
        getline(infile,line);
        vector<string> words;
        split1(line,words);
        //cout<<stod(words[0])<<" "<<stod(words[1])<<" "<<stod(words[2])<<" "<<stod(words[3])<<endl;
        input[i] = Customer(i,stod(words[0]),stod(words[1]),stod(words[2]),stod(words[3]));
    }
    ofstream myfile(argv[2]);
    FirstModel firstModel(N,&input);
    double workingTime=firstModel.getWorkingTime();
    myfile << std::fixed;
    myfile << std::setprecision(2);
    myfile << workingTime << endl;
    myfile << firstModel.getMaxCashierQueueLength() << endl;
    myfile << firstModel.getMaxBaristaQueueLength() << endl;

    vector<Cashier> cashiers = firstModel.getCashiers();
    for(int i=0; i<N; i++){
        double uti=cashiers[i].runningTime/workingTime;
        myfile<< uti <<endl;

    }

    vector<Barista> baristas = firstModel.getBaristas();
    for(int i=0; i<N/3; i++){
        double utilization=baristas[i].runningTime/workingTime;
        myfile<< utilization <<endl;
    }

    vector<Customer> customers = firstModel.getCustomers();

    for(int i=0; i<M; i++){
        //Customer current = customers[i];
        //cout<<current.getLeavingTime()<<" ";
        double l=customers[i].getLeavingTime();
        double a=customers[i].getArrivalTime();
        double turn=l-a;
        myfile << turn <<endl;
    }

    myfile<<endl;

    SecondModel secondModel(N,&input);
    workingTime=secondModel.getWorkingTime();
    myfile << workingTime << endl;
    myfile << secondModel.getMaxCashierQueueLength() << endl;
    vector<int> mbq=secondModel.getMaxBaristaQueueLengths();
    for(int i=0; i<N/3; i++){
        myfile << mbq[i]<< endl;
    }
    cashiers = secondModel.getCashiers();
    baristas = secondModel.getBaristas();
    customers = secondModel.getCustomers();
    for(int i=0; i<N; i++){
        double uti=cashiers[i].runningTime/workingTime;
        myfile<< uti <<endl;

    }
    for(int i=0; i<N/3; i++){
        double utilization=baristas[i].runningTime/workingTime;
        myfile<< utilization <<endl;
    }

    for(int i=0; i<M; i++){
        double l=customers[i].getLeavingTime();
        double a=customers[i].getArrivalTime();
        double turn=l-a;
       if(i!=M-1) myfile << turn <<endl;
        else myfile << turn;
    }

    return 0;
}