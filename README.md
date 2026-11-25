# 🏦 Simple Banking System

![C++](https://shields.io)
![Visual Studio](https://shields.io)
![Platform](https://shields.io)

A lightweight, file-driven console application written in *C++* that simulates core banking operations. Designed with clean procedural architecture and persistent text-file storage (Clients.txt) to ensure data integrity across sessions.

---

## 📋 Core Functionalities

| Operation | Description |
| :--- | :--- |
| *📋 Show Client List* | Renders all stored client records in a structured console table, with graceful handling for empty states. |
| *➕ Add New Client* | Validates account uniqueness and appends new client records to storage. |
| *🗑️ Delete Client* | Performs safe record removal with user confirmation before rewriting data. |
| *✏️ Update Client Info* | Modifies existing client credentials (PIN, Name, Phone, Balance) seamlessly. |
| *🔍 Find Client* | Retrieves and displays specific client details using their unique Account Number. |

---

## ⚙️ Technical Highlights
* *Persistent Storage:* Custom serialization and deserialization of structs (SdataClient) using #//# delimiters via fstream.
* *Data Management:* Efficient in-memory manipulation using std::vector before syncing changes back to disk.
* *Clean Modular Design:* Separation of concerns across input validation, file I/O, and UI rendering functions.

---

## 🚀 Getting Started

1. *Clone the repository:*
   bash
   git clone https://github.com
   
2. *Open the solution:* Launch Simple-Banking-System-cpp.slnx in *Visual Studio*.
3. *Compile & Run:* Press Ctrl + F5 to build and execute the application.
