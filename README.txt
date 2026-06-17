# 📚 Library Management System

![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![OOP](https://img.shields.io/badge/Paradigm-OOP-orange.svg)
![STL](https://img.shields.io/badge/STL-Vectors-green.svg)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen.svg)

A terminal-based **dual-portal Library Management System** built in C++, designed to simulate how a real library handles books, members, and lending operations — all while staying true to core Object-Oriented Programming principles. It supports two distinct user roles (**Librarian** and **Member**), each with a tailored set of permissions, and ships pre-loaded with a 100-book catalog spanning classic and modern literature.

---

## 🧠 Why This Project Matters

Most beginner C++ projects stop at "store data in a vector." This one goes a step further by modeling a **real-world access-controlled system**: a single application with two different experiences depending on who's logged in, a security layer that locks people out after repeated failed attempts, and a clean separation between *raw inventory*, *membership records*, and *active lending transactions*. It's a compact demonstration of how OOP class design maps directly onto a real operational workflow.

---

## ✨ Core Features

### 🔐 Secure Access Layer
- PIN-based login gate before any part of the system is accessible.
- **3-attempt lockout policy** — three incorrect PIN entries terminate the session entirely, mimicking real-world account security (e.g., ATM-style lockouts).

### 🧑‍💼 Librarian Portal
| Capability | Description |
|---|---|
| View All Books | Lists the entire catalog with title, author, and ID |
| Search by ID | Instant lookup of any book using its unique numeric ID |
| Search by Title | Case-insensitive title search (custom-built uppercase normalizer) |
| Add New Book | Inserts a new book record into the live in-memory catalog |
| Remove Book by ID | Deletes a book from the catalog with confirmation feedback |
| View All Members | Displays the full registered member directory |
| Add New Member | Registers a new library member with a unique ID |
| Remove Member | Removes a member record by ID |
| View Issued Books | Displays every book currently checked out |

### 🙋 Member Portal
| Capability | Description |
|---|---|
| View All Books | Browse the full catalog before deciding what to borrow |
| Issue Book | Check out a book by ID, with duplicate-issue prevention |
| My Issued Books | View currently issued books |
| Return Book | Return a borrowed book, removing it from active circulation |

### 🛡️ Role-Based Access Control (RBAC)
Once authenticated, the user selects a role — **Librarian** or **Member** — and is routed into a completely separate menu and permission set, so a member can never accidentally (or intentionally) access administrative functions like deleting books or members.

---

## 🏗️ Architecture & Class Design

The system is built around **four cooperating classes**, each with a single, well-defined responsibility:

```
┌─────────────┐     ┌──────────────┐     ┌──────────────┐
│    book     │     │    member    │     │  issuedbooks │
├─────────────┤     ├──────────────┤     ├──────────────┤
│ title       │     │ name         │     │ title        │
│ author      │     │ id           │     │ author       │
│ id          │     │ display_     │     │ id           │
│ display()   │     │ member()     │     │ display_     │
└─────────────┘     └──────────────┘     │ issuedbooks() │
       ▲                    ▲             └──────────────┘
       │                    │                     ▲
       └────────────────────┴─────────────────────┘
                             │
                    ┌────────────────┐
                    │     library      │
                    ├──────────────────┤
                    │ vector<book>       │
                    │ vector<member>     │
                    │ vector<issuedbooks>│
                    ├──────────────────┤
                    │ add/remove/search/ │
                    │ issue/return logic │
                    └──────────────────┘
```

- **`book`** — Encapsulates catalog data with a parameterized constructor for clean object creation.
- **`member`** — Represents a registered library user.
- **`issuedbooks`** — A dedicated record type for active loans, keeping "what's in the library" and "what's currently out" as logically separate concerns.
- **`library`** — The orchestrator class. Owns three independent `vector` containers and exposes all business logic (add, remove, search, issue, return) as clean member functions, keeping `main()` focused purely on menu flow.

This separation means the catalog, membership list, and circulation desk can all evolve independently — a small taste of the modularity that larger systems rely on.

---

## ⚙️ Technical Highlights

- **Dynamic Memory via STL `vector`** — All three data sets (books, members, issued books) are stored in dynamically resizable `vector` containers, avoiding fixed-size array limitations entirely.
- **Index-Safe Erasure** — Removal operations (`remove_book_by_id`, `remove_member_by_id`, `return_book_by_id`) iterate by index and use `vector::erase()` safely, with iterator-position handling to avoid undefined behavior.
- **Custom String Normalization** — A hand-written `toUppercase()` function (no `<algorithm>` shortcuts) demonstrates manual character-level manipulation using ASCII arithmetic, enabling case-insensitive title search.
- **Duplicate-Issue Guard** — `issue_book_by_id()` checks the active loans list *before* issuing, preventing the same book from being checked out twice simultaneously.
- **Pre-Seeded Realistic Dataset** — Launches with 100 real, recognizable book titles (Orwell, Tolkien, Dostoevsky, Rowling, Asimov, and more) and 6 members, so the system is immediately demoable without manual data entry.
- **Clean Console UX** — ANSI escape codes (`\033[1m`) are used for bold terminal headers, and a recurring `restart_menu()` helper creates a smooth looping menu experience instead of a one-shot script.

---

## 💻 Sample Interaction

```
********* WELCOME TO LIBRARY SYSTEM **********

PLEASE ENTER YOU FOUR DIGIT PIN TO LOGIN: 2007

WELCOME TO LIBRARY

PLEASE SELECT YOUR LOGIN ROLE:
1. LIBRARIAN
2. MEMBER
ENTER YOUR CHOICE: 2

1. VIEW ALL BOOKS
2. ISSUE BOOK
3. MY ISSUED BOOKS
4. RETURN BOOK
0. EXIT
> 2
PLEASE ENTER THE ID OF THE BOOK TO ISSUE: 1066
THE BOOK WITH THE ID 1066 EXISTS IN THE DATABASE
BOOK TITLE: DUNE
BOOK AUTHOR: FRANK HERBERT
BOOK ID: 1066
THE BOOK HAS BEEN ISSUED!
```

---

## 🚀 Getting Started

### Prerequisites
- A C++ compiler supporting C++11 or later (e.g., `g++`)

### Compile & Run
```bash
g++ library_management_system.cpp -o library
./library
```
> 💡 Login PIN for demo purposes: `2007`

---

## 🔭 Future Enhancements

This was deliberately built as a focused, in-memory OOP exercise. Natural next steps to evolve it into a production-style tool:
- **Persistent storage** — save/load catalog and membership data via file I/O or a lightweight database (SQLite) so data survives program restarts.
- **Per-member loan tracking** — link each issued book to the specific member who borrowed it (currently issued books are tracked globally, not per-member).
- **Due dates & fine calculation** — introduce borrow duration tracking and automated overdue fines.
- **Encrypted credentials** — replace the single hardcoded PIN with per-user hashed credentials.
- **Exception handling** — guard against invalid input types (e.g., entering text where a numeric ID is expected).

---

## 👤 Author

**Atharv Verma**
B.Tech, Computer Science and Engineering — SRM Institute of Science and Technology
📧 verma.atharv@gmail.com

---

*Built as part of a series of OOP-focused systems projects, exploring how core C++ concepts — classes, STL containers, and access control logic — combine to model real-world software systems.*
