#include <iostream>
struct Node
{
    int number;
    Node *sig;
    Node(int n)
    {
        number = n;
        sig = NULL;
    }
};

void insterToFinal(Node *&list, int n)
{
    Node *nn = new Node(n);
    if (list == NULL)
    {
        list = nn;
    }
    else
    {
        Node *aux = list;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nn;
    }
}

void printList(Node *list)
{
    Node *aux = list;
    while (aux != NULL)
    {
        std::cout << aux->number << " ";
        aux = aux->sig;
    }
    std::cout << std::endl;
}

int greatestSum(Node *list, Node *list2, Node *list3)
{
    Node *aux = list;
    Node *aux2 = list2;
    Node *aux3 = list3;

    int cAux = 0, cAux2 = 0, cAux3 = 0;
    while (aux != NULL)
    {
        cAux += aux->number;
        aux = aux->sig;
    }

    while (aux2 != NULL)
    {
        cAux2 += aux2->number;
        aux2 = aux2->sig;
    }

    while (aux3 != NULL)
    {
        cAux3 += aux3->number;
        aux3 = aux3->sig;
    }

    if (cAux == cAux2 && cAux2 == cAux3)
    {
        return 0;
    }
    else if (cAux >= cAux2 && cAux >= cAux3)
    {
        return 1;
    }
    else if (cAux2 >= cAux && cAux2 >= cAux3)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

int contOcurrences(Node *list, int n)
{
    Node *aux = list;
    int count = 0;
    while (aux != nullptr)
    {
        if (aux->number == n)
        {
            count++;
        }
        aux = aux->sig;
    }
    return count;
}

void repeateNumbers(Node *list1, Node *list2) {
    Node *current = list1;
    bool found = false;

    while (current != nullptr) {
        if (contOcurrences(list2, current->number) == 3) {
            found = true;
            std::cout << "The number: " << current->number << " is repeat exactly 3 times." << std::endl;
        }
        current = current->sig;
    }

    if (!found) {
        std::cout << "There aren'n numbers repeat exactly 3 times." << std::endl;
    }
}

int main()
{
    Node *list = NULL;
    Node *list2 = NULL;
    Node *list3 = NULL;

    // INSERT BURNED DATA, PROFFESORT HERE I BORNED DATA IN THE LOOP BECAUSE IT'S EASSIER, IN THE END THEY GIVE THE SAME DATA IN THE TRHEE LISTS;
    for (int i = 1; i < 6; i++)
    {
        insterToFinal(list, i);
        insterToFinal(list2, (i + 10) * 2);
        insterToFinal(list3, (i + 10) * 3);
    }

    std::cout << "\nBurnt numbers List #1: ";
    printList(list);

    std::cout << "\nBurnt numbers List #2: ";
    printList(list2);

    std::cout << "\nBurnt numbers List #3: ";
    printList(list3);
    // INSERT DATA BY USER;
    bool exit = false;
    int n;

    do
    {
        int option;
        std::cout << "\nHow many numbers do you want to enter: ";
        std::cin >> n;
        std::cout << "Which list do you want to put them on?\n"
                  << "1. List #1\n2. List #2\n3. List #3\n4. Exit\nEnter an option: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                int number;
                std::cout << "Enter the number: ";
                std::cin >> number;
                insterToFinal(list, number);
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                int number;
                std::cout << "Enter the number: ";
                std::cin >> number;
                insterToFinal(list2, number);
            }
            break;
        case 3:
            for (int i = 0; i < n; i++)
            {
                int number;
                std::cout << "Enter the number: ";
                std::cin >> number;
                insterToFinal(list3, number);
            }
            break;
        case 4:
            exit = true;
            break;
        default:
            std::cout << "Option not valid, try again." << std::endl;
            break;
        }

        if (!exit)
        {
            std::cout << "Do you want to insert new numbers again?\n"
                      << "1. Yes\n2. No\nEnter an option: ";
            std::cin >> option;
            if (option == 2)
            {
                exit = true;
            }
        }

    } while (!exit);

    // PRINT THE FINAL LIST;
    std::cout << "\nLIST #1: " << std::endl;
    printList(list);

    std::cout << "\nLIST #2: " << std::endl;
    printList(list2);

    std::cout << "\nLIST #3: " << std::endl;
    printList(list3);

    // PRINT THE GREATEST SUM;
    int greatest = greatestSum(list, list2, list3);
    if (greatest == 0)
    {
        std::cout << "\nThe three lists have the same sum." << std::endl;
    }
    else if (greatest == 1)
    {
        std::cout << "\nThe greatest sum is in the list #1." << std::endl;
    }
    else if (greatest == 2)
    {
        std::cout << "\nThe greatest sum is in the list #2." << std::endl;
    }
    else
    {
        std::cout << "\nThe greatest sum is in the list #3." << std::endl;
    }

    exit = false;
    do
    {
        int option;
        std::cout << "\nWhich list do you want to use to search the repeated numbers?\n"
                  << "1. List #1 with List #2\n2. List #2 with List #3\n3. List #1 with List #3\n4. Exit\nEnter an option: ";
        std::cin >> option;
        switch (option)
        {
        case 1:
            std::cout << "\nResult: \n";
            repeateNumbers(list, list2);
            break;
        case 2:
            std::cout << "\nResult: \n";
            repeateNumbers(list2, list3);
            break;
        case 3:
            std::cout << "\nResult: \n";
            repeateNumbers(list, list3);
            break;
        case 4:
            exit = true;
            break;
        default:
            break;
        }

        std::cout << "\nDo you want search the repeated number again?"
                    << "\n1. Yes\n2. No\nEnter an option: ";
        std::cin >> option;
        if (option == 2)
        {
            exit = true;
        }
    } while (!exit);

    std::cout << "\nThank you for use the program :) \n";
    return 0;
}