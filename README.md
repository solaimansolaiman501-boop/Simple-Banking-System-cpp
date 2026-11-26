# 🏦 Simple Banking System (C++)

A console-based Banking Management System written in *C++* using procedural programming and file handling (Clients.txt) to store and manage client records persistently.

---

## ✨ Features

### 📋 Main Menu (Client Management)
- *Show Client List:* Display all registered clients and their account details in a formatted table.
- *Add New Client:* Register new clients with unique account number validation.
- *Delete Client:* Remove existing client records safely with confirmation prompts.
- *Update Client Info:* Modify client details (Pin Code, Name, Phone, Balance).
- *Find Client:* Search for any client quickly using their Account Number.

### 💳 Transactions Menu (New Update)
A dedicated transactions module added to handle financial operations seamlessly:
- *Deposit:* Add funds to a specific client's account and update the balance immediately in Clients.txt.
- *Withdraw:* Deduct funds from a client's account with balance validation to prevent overdrafts.
- *Total Balances:* View a summary table of all client balances along with the total bank balance.

---

## 🛠️ Technologies & Concepts Used
- *Language:* C++
- *Data Storage:* Text File Handling (fstream with custom #//# record delimiters)
- *Data Structures:* struct, vector, enum
- *Architecture:* Modular functional programming

---

## 🚀 How to Run
1. Clone the repository:
   bash
   git clone https://github.com
   
2. Open the .sln or .cpp file in *Visual Studio* (or any C++ IDE).
3. Ensure Clients.txt is located in the same directory as the source .cpp file.
4. Build and run the project (Ctrl + F5).