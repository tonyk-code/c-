# Ethiopian License Plate Generator 🇪🇹

This is a C++ console application that generates and displays vehicle license plates for different types of use in Ethiopia. It handles various license categories such as Private, Government, Diplomatic, Commercial, and Specialized (e.g., UN, AU).

## 🔧 Features

- Select from 5 different license plate types:
  - Private
  - Government
  - Diplomatic
  - Commercial
  - Specialized
- Choose a region for local plates (13 Ethiopian regions supported)
- Automatically generate and preview possible plate combinations:
  - Number-only
  - Prefix + number (A-Z, AA-ZZ, AAA-ZZZ)
- Display the selected plate in a styled format
- Region-specific and international logic for license plate assignment

## 📷 Sample Output

## 🚀 How to Run

1. Make sure you have a C++ compiler installed (e.g., g++, clang++)
2. Clone this repository or download the code
3. Compile and run:

```bash
g++ -o plate_generator main.cpp
./plate_generator

📁 File Structure
main.cpp — the complete source code with logic and ASCII display

README.md — this file

👨‍💻 Contributors
This project is a collaborative effort between:

1. tonyk-code

2. isaacydk

Special thanks to isaacydk for collaborating on the design and logic of the license plate system.

📜 License
This project is open-source. You are free to use and modify it for educational purposes. Please credit the original authors if you publish or extend it.
