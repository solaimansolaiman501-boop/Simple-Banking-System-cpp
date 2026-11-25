
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip> 
using namespace std;

const string fileName = "Clients.txt";

enum enChose{ showClients = 1, Add, Delete, Update, Find, Exit };

struct SdataClient
{
    string AccountNumber = "";
    string Pincode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0;
};

void MainMenuScreen();

bool ClientExistsByAccountNumber(string);

enChose ReadUserInput()
{
    short answer;
    cout << "Chose What Do you want to Do? [1 to 6]???";
    cin >> answer;
    return enChose(answer);
    

}


SdataClient ReadNewClient()
{
    SdataClient Client;
    cout << "Enter Account Number : ";
    getline(cin >> ws, Client.AccountNumber);
    while (ClientExistsByAccountNumber(Client.AccountNumber))
    {
        cout << "Clients With Account Number [" << Client.AccountNumber << "]Already exists. ";
        cout << "enter another accout number \n";
        getline(cin >> ws, Client.AccountNumber);

    }
    
    cout << "Enter PinCode : ";
    getline(cin, Client.Pincode);
    cout << "Enter Name : ";
    getline(cin, Client.Name);
    cout << "Enter Phone Number : ";
    getline(cin, Client.Phone);
    cout << "Enter Account Balance : ";
    cin >> Client.AccountBalance;

    return Client;
}

string ReadString()
{
    string accountnum = "";
    cout << "Please Enter Account Number : ";
    getline(cin>>ws, accountnum);
    return accountnum;
}


void ReadUpdatedClient(vector<SdataClient>& vClients,string AccountNum)
{
    SdataClient UpdatedClient;

    for (SdataClient& c : vClients)
    {
        if (c.AccountNumber == AccountNum)
        {
            UpdatedClient.AccountNumber = AccountNum;
            cout << "Enter PinCode : ";
            getline(cin >> ws, UpdatedClient.Pincode);
            cout << "Enter Name : ";
            getline(cin, UpdatedClient.Name);
            cout << "Enter Phone Number : ";
            getline(cin, UpdatedClient.Phone);
            cout << "Enter Account Balance : ";
            cin >> UpdatedClient.AccountBalance;
            c = UpdatedClient;
            break;
        }
        
    }

}


string ConvertRecordToLine(SdataClient c2, string delim)

{
    string stClientData = "";
    stClientData += c2.AccountNumber + delim;
    stClientData += c2.Pincode + delim;
    stClientData += c2.Name + delim;
    stClientData += c2.Phone + delim;
    stClientData += to_string(c2.AccountBalance);

    return stClientData;
}


vector <string> SplitStringIntoVector(string str, string delim)
{
    vector<string> vwords;
    string sword;
    size_t pos = 0;

    while ((pos = str.find(delim)) != string::npos)
    {
        sword = str.substr(0, pos);
        if (sword != " ")
            vwords.push_back(sword);
        str.erase(0, pos + delim.length());
    }
    if (str != " ")
        vwords.push_back(str);

    return vwords;
}

SdataClient convertLineToRecord(string str)
{
    SdataClient Client;
    vector<string> vDataClient = SplitStringIntoVector(str, "#//#");
    Client.AccountNumber = vDataClient[0];
    Client.Pincode = vDataClient[1];
    Client.Name = vDataClient[2];
    Client.Phone = vDataClient[3];
    Client.AccountBalance = stod(vDataClient[4]);

    return Client;
}


bool ClientExistsByAccountNumber(string accountNum )
{
    fstream myfile;
    myfile.open(fileName, ios::in);
    if (myfile.is_open())
    {

        string line;
        SdataClient client;
        while (getline(myfile, line))
        {
            client = convertLineToRecord(line);
            if (client.AccountNumber == accountNum)
            {
                myfile.close();
                return true;
            }
        }
     
    }
    return false;
}


vector<SdataClient> LoadDataFromFile()
{
    vector <SdataClient> vClients;
    fstream myfile;
    SdataClient Client;

    myfile.open(fileName, ios::in);
    if (myfile.is_open())
    {
        string stline;
        while (getline(myfile, stline))
        {
            Client = convertLineToRecord(stline);
            vClients.push_back(Client);
        }
        myfile.close();
    }
    return vClients;

}


void PrintClient(SdataClient client)
{


    cout << "| " << left << setw(20) << client.AccountNumber ;
    cout << "| " << left << setw(15) << client.Pincode;
    cout << "| " << left << setw(40) << client.Name;
    cout << "| " << left << setw(15) << client.Phone;
    cout << "| " << left << setw(15) << client.AccountBalance << endl;

}


void PrintAllClients(SdataClient client, vector<string>& vClients)
{

    cout << "\t\t\t\t\t\t Client List (" << vClients.size() << ") Client(s)\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";

    cout << "| " << left << setw(20) << "Account Number";
    cout << "| " << left << setw(15) << "Pin Code";
    cout << "| " << left << setw(40) << "Name";
    cout << "| " << left << setw(15) << "Phone";
    cout << "| " << left << setw(15) << "Balance";


    cout << "\n-------------------------------------------------------------------------------------------------------------\n";


    for (string& line : vClients)
    {
        client = convertLineToRecord(line);
        PrintClient(client);

    }



}


void PrintClientCard(SdataClient client)
{
    
  cout << "\nAccount Number : " << client.AccountNumber << endl;
  cout << "Pin Code : " << client.Pincode << endl;
  cout << "Name : " << client.Name << endl;
  cout << "Phone : " << client.Phone << endl;
  cout << "Balance : " << client.AccountBalance << endl;
}


void PrintMenuScreen()
{
    cout << "===========================================";
    cout << "\n                Main Menu Screen\n";
    cout << "===========================================\n";

    cout << "\t(1)Show Client List.\n";
    cout << "\t(2)Add New Client.\n";
    cout << "\t(3)Delete Client.\n";
    cout << "\t(4)Update Client Info.\n";
    cout << "\t(5)Find Client.\n";
    cout << "\t(6)Exit.\n";
    cout << "===========================================\n";


}


void AddClientTOFile()
{
    fstream myfile;

    SdataClient NewClient;
    NewClient = ReadNewClient();

    string sDataClient = ConvertRecordToLine(NewClient, "#//#");

    myfile.open(fileName, ios::out | ios::app);

    if (myfile.is_open())
    {
        myfile << sDataClient << endl;

        myfile.close();
    }



}


bool FindClientByAccountNumber(SdataClient& client, string accountnum)
{
    vector<SdataClient> vClients;
    vClients = LoadDataFromFile();

    for (SdataClient& c : vClients)
    {

        if (c.AccountNumber == accountnum)
        {
            client = c;
            return true;
        }
    }
    return false;
}

void MainMenuBack()
{
    cout << "\nPress any ket to go back to main menu screen...";

    system("pause > nul ");
    MainMenuScreen();
}



void ShowAllClient()
{
 

    SdataClient Client;
    vector <string> vClients;
    fstream myfile;
    myfile.open(fileName, ios::in);

    if (myfile.is_open())
    {
        string stline;
        while (getline(myfile, stline))
            vClients.push_back(stline);

        myfile.close();
    }

    PrintAllClients(Client, vClients);

    MainMenuBack();
   
}


void  PrintHeaderAdd()
{

    cout << "===============================================\n";

    cout << "                  Add New Client Screen \n";
        
    cout << "===============================================\n";
}




void AddNewClient()
{

    PrintHeaderAdd();

    char AddNew = 'y';

    do {
        system("cls");
        cout << "\nAdding New Client : \n" << endl;
        AddClientTOFile();

        cout << "Client Added successfully,Do you want to add more ???";
        cin >> AddNew;

    } while (AddNew == 'y' || AddNew == 'Y');

    MainMenuBack();

}


void PrintHeaderDelete()
{

    cout << "===============================================\n";

    cout << "                  Delete Client Screen \n";

    cout << "===============================================\n";

}



void DeleteClient(SdataClient client)
{
    vector<SdataClient> vClients;
    vClients = LoadDataFromFile();
    fstream myfile;
    myfile.open(fileName, ios::out);

    string sDataLine = "";

    if (myfile.is_open())
    {

        for (SdataClient& c : vClients)
        {
            if (c.AccountNumber != client.AccountNumber)
            {

                sDataLine = ConvertRecordToLine(c, "#//#");
                myfile << sDataLine << endl;
            }
        }

        myfile.close();
        vClients = LoadDataFromFile();
    }

}



void DeleteClientByAccountNumber()
{

    PrintHeaderDelete();

    string AccountNumber = ReadString();
    SdataClient client;
    char Answer = 'y';


    if (FindClientByAccountNumber(client, AccountNumber))
    {
        cout << "the following are the client details : \n";
        PrintClient(client);
        cout << "\nAre you sure You want to delete this client ? " << endl;
        cin >> Answer;
        if (Answer=='y'||Answer=='Y')
        {
            DeleteClient(client);
            cout << "\nclient Deleted successfully .\n";
        }

    }

    else
    {
        cout << "client with account number(" << AccountNumber << ") is not found !!\n";
    }

    MainMenuBack();
}


void UpdateClient(SdataClient& client, string AccountNum)
{
    vector<SdataClient> vClients;
    vClients = LoadDataFromFile();

    ReadUpdatedClient(vClients, AccountNum);

    fstream myfile;
    myfile.open(fileName, ios::out);

    string sDataLine = "";

    if (myfile.is_open())
    {

        for (SdataClient& c : vClients)
        {
            sDataLine = ConvertRecordToLine(c, "#//#");
            myfile << sDataLine << endl;

        }


        myfile.close();


    }

}


void PrintFindHeader()
{

    cout << "===============================================\n";

    cout << "                  Update Client Screen \n";

    cout << "===============================================\n";


}

void UpdateClientByAccountNumber()
{

    PrintFindHeader();

    string AccountNumber = ReadString();
    SdataClient client;
    char Answer = 'y';

    if (FindClientByAccountNumber(client, AccountNumber))
    {
        cout << "\nthe following are the client details : \n\n";
        PrintClientCard(client);
        cout << "\nAre you sure You want to Update this client ? " << endl;
        cin >> Answer;
        if (tolower(Answer)=='y')
        {
            UpdateClient(client, AccountNumber);
            cout << "\nclient Updated successfully .\n";
        }

    }

    else
    {
        cout << "client with account number(" << AccountNumber << ") is not found !!\n";
    }



    MainMenuBack();


}

void PrintHeaderFind()
{
    cout << "--------------------------------------\n";
    cout << "                 Find Client Screen \n";
        cout << "---------------------------------------" << endl;

}


void FindClient()
{

    PrintHeaderFind();

    string AccountNum = ReadString();
    SdataClient client;

    if (FindClientByAccountNumber(client, AccountNum))
    {
        PrintClientCard(client);
    }
    else
        cout << "client with account number [" << AccountNum << "]is not found!" << endl;

    MainMenuBack();
}



void PerformMainMenuScreen()
{
    
    enChose chose = ReadUserInput();
    switch (chose)
    {

    case enChose::showClients:
        system("cls");
        ShowAllClient();
        break;
    case enChose::Add:
        system("cls");
        AddNewClient();
        break;
    case enChose::Delete:
        system("cls");
        DeleteClientByAccountNumber();
        break;
    case enChose::Update:
        system("cls");
        UpdateClientByAccountNumber();
        break;
    case enChose::Find:
        system("cls");
        FindClient();
        break;
    case enChose::Exit:
        exit(0);
        break;

    }

}

void MainMenuScreen()
{
    system("cls");

    PrintMenuScreen();

    PerformMainMenuScreen();
}

int main()
{

   
    MainMenuScreen();


    system("pause > nul ");
    return 0;
}

