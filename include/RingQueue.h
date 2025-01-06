#ifndef RINGQUEUE_H
#define RINGQUEUE_H

#include <array>  // För att använda fält med fast storlek i vår kö

// Klassen RingQueue är en cirkulär kö som gör det möjligt att lägga till och ta bort objekt effektivt
template <typename T, std::size_t N>
class RingQueue {
public:
    RingQueue() : head(0), tail(0), full(false) {}

    // Metod för att lägga till ett element i kön (enqueue)
    void enqueue(const T& value) {
        data[tail] = value;  // Lägg till det nya värdet på den aktuella positionen för "tail"
        tail = (tail + 1) % N;  // Flytta "tail" framåt (använd modulo för att börja om från början om slutet nås)

        if (full) {
            head = (head + 1) % N;  // Om kön är full, flytta "head" framåt för att skriva över det äldsta elementet
        }

        full = (tail == head);  // Kön är full när "tail" kommer ikapp "head"
    }

    // Metod för att hämta ett element från kön utan att ta bort det (peek)
    bool peek(std::size_t index, T& value) const {
        if (isEmpty() || index >= size()) return false;  // Returnera false om indexet är ogiltigt eller kön är tom
        value = data[(head + index) % N];  // Beräkna det faktiska indexet med modulo-aritmetik för att hantera köns cirkulära natur
        return true;  // Lyckades hämta värdet
    }

    // Metod för att få det aktuella antalet element i kön
    std::size_t size() const {
        if (full) return N;  // Om kön är full, returnera den totala kapaciteten
        if (tail >= head) return tail - head;  // Om det inte är något omslag, beräkna storleken direkt
        return N - head + tail;  // Om det finns omslag, beräkna storleken korrekt
    }

    // Metod för att kontrollera om kön är tom
    bool isEmpty() const {
        return !full && (head == tail);  // Kön är tom om den inte är full och "head" är lika med "tail"
    }

private:
    std::array<T, N> data;  // Fält för att lagra köelementen
    std::size_t head;       // Pekar på det äldsta objektet i kön
    std::size_t tail;       // Pekar på nästa lediga plats i kön
    bool full;              // Indikerar om kön är full
};

#endif  // RINGQUEUE_H