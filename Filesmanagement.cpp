// Filesmanagement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//// FileManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream> // working with files requires fstream to be included
#include <sstream>//To include string  read a row from the file//
using namespace std;

//structure definition
struct SuperMarket {
    string itemNo;
    string itemName;
    float itemPrice;

    //constructor
    SuperMarket(string ino = "", string iname = "", float iprice = 0) {
        itemNo = ino;
        itemName = iname;
        itemPrice = iprice;
    }

};

//function prototypes

//int main()
{
    SuperMarket sm[2];
    SuperMarket myData("wb101", "White Bread", 2.75);
    cout << myData.itemName;
    //Modes of opening the file - out, in, app
    //Write into the file using out mode for the first time. It will overwrite any content
    //Retrieve from the file usng in mode
    //
    //ofstream outFile; //ofstream is the keyword that is used to declare a file handling variable
    ofstream appFile;
    //outFile.open("D:/Users/092834/OneDrive - UP Education/Desktop/CS103/July2021/FileManagement/supermarket.csv",ios::out);
    appFile.open("D:/Users/092834/OneDrive - UP Education/Desktop/CS103/July2021/FileManagement/supermarket.csv", ios::app);
    int i;
    for (i = 0; i < 2; i++) {
        cin.ignore();
        cout << "\nEnter the item number: ";
        getline(cin, sm[i].itemNo);

        cout << "\nEnter the item name: ";
        getline(cin, sm[i].itemName);

        cout << "\nEnter the item price: ";
        cin >> sm[i].itemPrice;

        //Writing with outFile or appending with appfile
        //outFile << sm[i].itemNo << "," << sm[i].itemName << "," << sm[i].itemPrice << endl;
        appFile << sm[i].itemNo << "," << sm[i].itemName << "," << sm[i].itemPrice << endl;
    }

    appFile.close();
}

//#include <iostream>
//#include<string>
//#include<fstream>//Working with files requires fstream to be included//
//using namespace std;
//
////structure definition
//struct SuperMarket{
//	string itemNo;
//	string itemName;
//	float itemPrice;
//
//
//	//Constructor//
//	SuperMarket(string ino = "", string iname = "", float iprice = 0) {
//		itemNo = ino;
//		itemName = iname;
//		itemPrice = iprice;
//	}
//
//
//};
//
//int main()
//{
//	SuperMarket sm[2];
//	ofstream outFile;//ostream is the key word used to declare a file handling variable//
//	// example outfile.open(path&name,mode)//
//	outFile.open("C:/Users/270161235/OneDrive - UP Education/Desktop/C++103/Filesmanagement/supermarket.csv", ios::out);
//	for (int i = 0; i < 2; i++) {
//		cin.ignore();//clears the buffer//
//		cout << "\nEnter Item number :";
//		getline(cin, sm[i].itemNo);
//
//		cout << "\nEnter the item name: ";
//		getline(cin, sm[i].itemName);
//
//		cout << "\nEnter the item price: ";
//		cin >> sm[i].itemPrice;
//
//		outFile << sm[i].itemNo<< "," << sm[i].itemName << "," << sm[i].itemPrice << endl;;
//	}
//
//
//	outFile.close();
//}
/////Reading or retrivin from the file//
  //************************
    //Reading or retrieving from the file
    //************************

int main(){

SuperMarket sm[2], supermarket;

SuperMarket myData("wb101", "White Bread", 2.75);
cout << myData.itemName;
   //open file
   // ifstream inFile; //specifically to handle input mode
    //fstream handles all modes - in, out, app
   // inFile.open(, );
ifstream inFile("D:/Users/092834/OneDrive - UP Education/Desktop/CS103/July2021/FileManagement/supermarket.csv", ios::in);
// struct Employee transaction;
string line; //to store the line that is read from the line
int linenum = 0; //used as loop index
SuperMarket smarket[5];
while (getline(inFile, line)) { //reads a line from csv file
    //cout << line;
    istringstream linestream(line); //stringstream separates the line values
    string item;
    getline(linestream, item, ',');//read separated linestream values and store in item and add comma

    supermarket.itemNo = item; //store the separated value in structure member empname

    getline(linestream, item, ',');
    stringstream ss(item); //convert the data type from string to int
    ss >> supermarket.itemName;//store the separated value in structure member empid
    smarket[linenum] = supermarket;//push the structure into the array 
    linenum++; //index variable incremented
}


inFile.close();
//close file

}

//functions