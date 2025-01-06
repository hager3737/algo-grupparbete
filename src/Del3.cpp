#include "../include/RingQueue.h"
#include <string>
#include <iostream> // För in-/utmatningsoperationer

void runPart3() {
    // Skapa en RingQueue som lagrar strängar med en kapacitet på 5
    RingQueue<std::string, 5> queue;

    // Steg 1: Lägg till element i kön och demonstrera överskrivning
    std::cout << "\nDel 3: Ring Buffer (cirkulär kö) demonstration" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    std::cout << "Steg 1: Lägg till element i kön och demonstrera överskrivning" << std::endl;

    // Lägg till 5 element i kön
    queue.enqueue("Anna");
    queue.enqueue("Bertil");
    queue.enqueue("Calle");
    queue.enqueue("David");
    queue.enqueue("Erik");

    // Visa de aktuella elementen i kön
    std::cout << "- Kölista med initiala element (storlek " << queue.size() << "):" << std::endl;
    for (std::size_t i = 0; i < queue.size(); ++i) {
        std::string value;
        if (queue.peek(i, value)) {
            std::cout << i << ": " << value << std::endl;
        }
    }

    // Lägg till ett nytt element ("Kenneth") som kommer att skriva över det äldsta elementet ("Anna")
    queue.enqueue("Kenneth");

    // Visa den uppdaterade kön efter att "Kenneth" lagts till
    std::cout << "\n- Kölista efter att ett nytt element lagts till (storlek " << queue.size() << "):" << std::endl;
    for (std::size_t i = 0; i < queue.size(); ++i) {
        std::string value;
        if (queue.peek(i, value)) {
            std::cout << i << ": " << value << std::endl;
        }
    }
    std::cout << std::endl;

    // Steg 2: Sök efter "Bertil" med en metod som liknar binärsökning
    std::cout << "Steg 2: Binärsökning\n";
    std::string search = "Bertil";
    std::size_t start = 0;
    std::size_t end = queue.size() - 1;
    std::string current;
    bool found = false;

    std::cout << "Söker efter \"" << search << "\"...\n" << std::endl;
    while (start <= end) {
        std::size_t currentIndex = (start + end) / 2;

        // Hämta värdet på den aktuella indexpositionen
        if (!queue.peek(currentIndex, current)) {
            std::cout << "Fel vid åtkomst av index " << currentIndex << std::endl;
            break;
        }

        std::cout << "Kontrollerar index " << currentIndex << ": " << current << std::endl;

        if (current == search) {
            found = true;  // Elementet hittades
            break;
        }
        if (current < search) {
            start = currentIndex + 1;  // Sök i den högra halvan
        } else {
            end = currentIndex - 1;  // Sök i den vänstra halvan
        }
    }

    if (found) {
        std::cout << "\nHittade: " << search << std::endl;
    } else {
        std::cout << "\nHittades inte: " << search << std::endl;
    }
}
