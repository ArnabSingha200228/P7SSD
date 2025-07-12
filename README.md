# 📟 P7SSD : PIC-driven 7-Segment Scrolling Display

A PIC16F72 microcontroller-based text scroller using dual 4-digit 7-segment displays. The system continuously scrolls custom inputed text across the display using a minimal interface and simple embedded logic.

---

## 🔧 Features

- 🧠 **Powered by PIC16F72** microcontroller
- 🔢 **Two 4-digit Common Anode 7-Segment Displays** (8 digits total)
- ⌨️ **Three Push-Button Interface**:
    1. **Scroll** through characters at input time  
    2. **Select** desired character  
    3. **Finalize** the input and start scrolling
- 🔄 **Continuous Right-to-Left Text Scrolling**
- 🔌 **+5V Input Voltage**
- 💾 **Programmed in C**
- 🧪 **Simulated using Proteus** before physical prototyping

---

## 🛠️ How It Works

1. On powering the device, you can scroll through predefined characters using **Button 1**.
2. Press **Button 2** to select the current character and move to the next position.
3. After entering the full message, press **Button 3** to **start scrolling** the text.
4. The entered message scrolls across the 7-segment displays in a loop.

---

## 🖥️ Tools & Components Used

- **Microcontroller**: PIC16F72
- **Display**: Two 4-digit common anode 7-segment displays
- **Buttons**: 3 tactile push-buttons for input
- **Power**: 5V DC supply
- **Software**:
  - mikroC PRO IDE for C programming
  - Proteus for circuit simulation
- **Hardware**:
  - Soldering prototyping board for final build
  - Supporting resistors, capacitors, crystal oscillator, and wiring

---

## 🚀 Future Improvements

- EEPROM save for input string persistence
- Brightness control via PWM
- Serial input via UART
- Support for more characters or symbols

---

## 👨‍🔧 Author

**Arnab Singha**  
> 👨‍💻 Crafted with curiosity in embedded systems using bare-metal C and classic embedded design techniques.
