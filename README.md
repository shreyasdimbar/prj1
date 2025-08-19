<div align="center">

# 📖 Simple CLI Library Management System 📖

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Console-lightgrey.svg)

</div>

> A straightforward, console-based library management system written in C++. This application allows users to issue, submit, and track books using a command-line interface and local text files for data persistence.

---

## ✨ Core Features

* **📤 Issue Books**: Issue available books to a user by linking the book title to a unique PRN (Personal Registration Number).
* **📥 Submit Books**: Return a previously issued book, removing the record from the system.
* **📚 View All Records**: Display a formatted list of all currently issued books and who borrowed them.
* **🔍 Search by PRN**: Look up all the books issued to a specific user.
* **💾 Data Persistence**: All issued book records are saved to `issued_books.txt`, so data is not lost between sessions.

---

## 💻 Technologies Used

This project is built entirely with **C++** and leverages standard libraries for its functionality:

* **`iostream`**: For all console input and output.
* **`fstream`**: For file handling (reading from and writing to `.txt` files).
* **`vector`**: To manage lists of books and records efficiently in memory.
* **`sstream`**: To parse comma-separated data from the records file.

---

## 🧠 How It Works

The program operates using two simple text files as its database:

* `AVAbookNames.txt`: A list of all available book titles. [cite_start]Each book is on a new line[cite: 1, 2, 3].
* `issued_books.txt`: Acts as the database for all borrowed books. [cite_start]It stores records in a `PRN,Book Title` format[cite: 4]. The application reads this file at startup and writes back to it upon closing.

---

## 🚀 Getting Started

To get a local copy up and running, follow these simple steps.

### Prerequisites

You need a C++ compiler installed on your system. The most common one is **g++**.

### Installation & Execution

1.  **Clone the repository** (or download the files into a single folder).

2.  **Check your files.** Make sure `main.cpp`, `AVAbookNames.txt`, and `issued_books.txt` are all in the same directory.

3.  **Compile the code.** Open your terminal, navigate to the project directory, and run:
    ```sh
    g++ main.cpp -o library_system
    ```

4.  **Run the application!**
    ```sh
    ./library_system
    ```

---

## 📖 Usage Guide

Once the application is running, you will be greeted with the main menu.



```
                  <------- Welcome ------->

                   Sat Aug 10 11:15:23 2025
```

Choose any of the options below -\>

```
  1. Do you want to issue any Book
  2. Do you want to see any Perticuler Record
  3. Want to see total previous Records
  4. Submit a Book
  5. Close Programme
```



* **To Issue a Book**: Select option `1`, enter the exact book title, and provide your PRN.
* **To Submit a Book**: Select option `4`, enter your PRN, and then the title of the book to return.
* **To View Records**: Use option `2` for a specific user or option `3` for all records.
* **To Exit**: Select option `5`. This will save all your changes and close the program.

<br>

<div align="center">
    <i>This README was created with the help of an AI assistant.</i>
</div>

