# **Multi-Client Chat Application (C, Sockets, Pthreads)**

## **Project Overview**
This project is a **real-time chat application** built in **C** using **TCP sockets** and **pthreads**. It allows multiple clients to connect to a server and chat with each other. Users can send **public messages** (visible to all clients) and **private messages** (sent to a specific user using `@username`).

---

## **Understanding the Code**

### **Client Side**

#### **1️⃣ `main()` Function (Client)**
- Creates a **TCP socket** to connect to the server.
- Asks the user for a **username** and sends it to the server.
- Starts a **separate thread** to listen for incoming messages.
- Continuously reads user **input** and sends messages to the server.
- Disconnects if the user types **"exit"**.

#### **2️⃣ `receive_messages(void *arg)` Function**
- Runs in a **separate thread**.
- Continuously **listens** for messages from the server and prints them.
- Stops if the **connection is lost**.

---

### **Server Side**

#### **1️⃣ `main()` Function (Server)**
- Creates a **TCP socket** to listen for incoming connections.
- Accepts new **clients** and stores their usernames.
- Spawns a **new thread** for each client to handle messages.

#### **2️⃣ `client_handler(void *arg)` Function**
- Handles messages from a **specific client**.
- If a message starts with **`@username`**, it is treated as a **private message** and sent to that user only.
- Otherwise, the message is **broadcasted** to all connected users.
- If a client **disconnects**, their socket is **closed and removed** from the active list.

#### **3️⃣ `clients_mutex` (Mutex for Thread Safety)**
- The server has **multiple threads** handling different clients.
- **Mutex locks** prevent multiple threads from modifying the client list at the same time.

---

## **📜 How to Use**

### **1️⃣ Compile the Code**
```bash
gcc server.c -o server -pthread
gcc client.c -o client -pthread
```

### **2️⃣ Start the Server**
```bash
./server
```

### **3️⃣ Start the Client**
```bash
./client
```
- Enter a **username** when prompted.
- Start **chatting!**

### **4️⃣ Chat Using Commands**
- **Public Message:** Type and press **Enter**.
- **Private Message:** `@username Hello!` (Sends a private message).
- **Exit:** Type **"exit"** to leave the chat.



---
