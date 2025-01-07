#include "../include/Del2.h"
#include <iostream>
#include <string>

// En klass för en kö som kan hålla upp till en viss mängd data
template <typename T, size_t Size>
class Queue {
private:
    T data[Size];       // Här sparas alla element i kön
    size_t front = 0;   // var nästa element ska tas bort
    size_t rear = 0;    // var nästa element ska läggas till
    size_t count = 0;   // Håller koll på hur många element som finns i kön

public:
    // Lägger till ett element i kön
    bool enqueue(const T& value) {
        // Om kön är full, returnera false
        if (count == Size) return false;

        // Lägg till elementet på rätt plats
        data[rear] = value;

        // Flytta till nästa plats, starta om från början om vi når slutet
        rear = (rear + 1) % Size;

        // Öka antalet element i kön
        ++count;
        return true;
    }

    // Tar bort ett element från kön
    bool dequeue(T& value) {
        // Om kön är tom, returnera false
        if (count == 0) return false;

        // Ta bort elementet från rätt plats och spara det i variabeln 'value'
        value = data[front];

        // Flytta fram fronten till nästa element
        front = (front + 1) % Size;

        // Minska antalet element i kön
        --count;
        return true;
    }
};

// Här börjar programmet
    void runPart2(){
   

    // Skapa en kö för heltal (int) som kan lagra upp till 5 element
    Queue<int, 5> q;

    // Försök att lägga till 6 element i kön
    for (int i = 1; i <= 6; ++i) {
        // Om vi kan lägga till, skriv ut vilket värde som lades till
        // Annars skriv att kön är full
        std::cout << (q.enqueue(i) ? "Enqueued: " + std::to_string(i) : "Queue is full!") << std::endl;
    }

    int value; // Variabel för att spara värdet som tas bort

    // Ta bort alla element från kön och skriv ut vad som tas bort
    while (q.dequeue(value)) {
        std::cout << "Dequeued: " << value << std::endl;
    }

    // Försök att ta bort från en tom kö
    if (!q.dequeue(value)) {
        std::cout << "Queue is empty!" << std::endl;
    }

    
}

