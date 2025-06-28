# 🚗💼 Car Rental Service System – C++ Project

> 🧑‍💻 A practical simulation of a car rental company using **C++**, showcasing real-world programming concepts like **structs**, **file handling**, **arrays**,**typedef** ,**pointers**, **strings**, **loops**, and **functions**.

---

## 👥 Team Members

| 👤 Name            | 🆔 ID    |
|--------------------|---------|
| YESEHAK KEBERE     | GIO444  |
| YISEHAK DEREJE     | 0P3331  |
| NATHNAEL GASHAW    | TWO402  |

---

## 🎯 Project Objective

Design and implement a simple **Car Rental Management System** in C++ that mimics real-life car rental operations, including:

- ✔️ Customer registration  
- ✔️ Listing available cars  
- ✔️ Searching & renting cars  
- ✔️ Returning cars  
- ✔️ Maintaining rental history  

All implemented using foundational C++ concepts to reinforce our learning through a real-world inspired application.

---

## 🧩 Core Features

### 🔹 1. Customer Registration – *“Becoming a Client”*
Captures new customer details including:

- Full name, ID, license number  
- Contact info (phone, email, address)  
- Gender and age  

📁 **Stored in**: `customers.txt`  
🔧 **Uses**: `struct`, file output (`ofstream`), input validation

---

### 🔹 2. Car Listing – *“What's in Our Garage?”*

Displays all available cars read from `cars.txt`, each with:

- Plate Number (e.g., AB-1234)  
- Model (e.g., Toyota Yaris)  
- Rent per day  
- Availability status (Yes / No)

🔧 **Uses**: file input (`ifstream`), structs, arrays

---

### 🔹 3. Car Search – *“Got a Toyota?”*

- User inputs a car model (case-insensitive)  
- System shows matching or similar options  
- If accepted → proceed to rent  
- If declined → return to menu or exit

🔧 **Uses**: strings, conditionals, search logic

---

### 🔹 4. Rent a Car – *“Drive Away!”*

- User selects a car and number of rental days  
- Total cost is calculated  
- Rental info logged in `rental_history.txt`  
- Availability updated in `cars.txt`

📄 Example:  
```
Model: Honda Civic  
Rent/day: $30  
Days: 4  
Total = $120
```

---

### 🔹 5. Return a Car – *“Back from Your Trip?”*

- Car status is updated to **Available** in `cars.txt`  
- No deletion of records — maintains history

🔧 Ensures consistent tracking and supports future audits.

---

### 🔹 6. Rental History Log – *“Manager’s Ledger”*

Displays:

- Customer details  
- Rented car  
- Duration  
- Total payment  
- Return status  

📁 **Logs kept in**: `rental_history.txt`  
🔍 Accessible by the manager for tracking and reporting.

---

## 🗃️ File Structure

| 📄 File Name         | 📌 Description                                           |
|----------------------|----------------------------------------------------------|
| `main.cpp`           | Main logic and menu loop of the system                  |
| `cars.txt`           | Car database with plate, model, rate, availability      |
| `customers.txt`      | Registered customer information                         |


---

## 🧠 Concepts Practiced

- 🧩 **Structs** – Group related data for cars and customers  
- 📂 **File I/O** – Persist and update data in `.txt` files  
- 📌 **Arrays & Pointers** – Manage multiple cars and dynamic records  
- 🔁 **Loops & Logic** – For interaction, validation, and flow control  
- 🛠️ **Modular Functions** – Separated into reusable tasks  
- 🔡 **String Manipulation** – Search, compare, and modify car models  

---

## 🔁 User Interaction Flow

```
1. Launch program (main menu in loop)
2. Choose: Rent or Return
3. If Rent:
   → View available cars
   → Search/select a model
   → Enter rental days
   → Confirm rental and view cost
   → Update files
4. If Return:
   → Enter model and plate
   → Mark as Available
5. Exit when done
```

---

## ✅ Sample Scenario

```
Customer: John Doe
Requested: Toyota Corolla
Availability: ❌ Not available
Suggestion: Honda Civic
Accepted: ✅
Rented: 4 days × $30/day = $120

System updates:
- cars.txt → Honda Civic marked Unavailable
- rental_history.txt → Entry added with details
- On return → Honda Civic marked Available
```

---

## 🎉 Conclusion

This project demonstrates how real-world applications can be built using core C++ programming concepts. It gives hands-on experience in managing data, structuring code, and simulating practical business logic — making it ideal for students, beginners, or C++ learners.