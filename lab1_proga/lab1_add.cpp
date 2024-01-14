#include <iostream>
#include <map>
#include <iomanip>

struct BankAccount {
    int accountNumber;
    double balance;
    BankAccount(int accNum, double bal) : accountNumber(accNum), balance(bal) {}
};

int nextAccountNumber = 1001;
std::map<int, BankAccount> accounts;

void openAccount(double initialDeposit) {
    if (nextAccountNumber <= 1100) {
        accounts[nextAccountNumber] = BankAccount(nextAccountNumber, initialDeposit);
        std::cout << "Îòêðûò íîâûé ñ÷åò " << nextAccountNumber << " ñ íà÷àëüíûì äåïîçèòîì " << initialDeposit << std::endl;
        nextAccountNumber++;
    }
    else {
        std::cout << "Íå óäàëîñü îòêðûòü ñ÷åò. Ïðåâûøåí ëèìèò êîëè÷åñòâà ñ÷åòîâ." << std::endl;
    }
}

void getBalance(int accountNumber) {
    if (accounts.find(accountNumber) != accounts.end()) {
        std::cout << "Íîìåð ñ÷åòà: " << accountNumber << ", Áàëàíñ: " << accounts[accountNumber].balance << std::endl;
    }
    else {
        std::cout << "Ñ÷åò " << accountNumber << " íå ñóùåñòâóåò" << std::endl;
    }
}

void deposit(int accountNumber, double amount) {
    if (accounts.find(accountNumber) != accounts.end()) {
        accounts[accountNumber].balance += amount;
        std::cout << "Íîìåð ñ÷åòà: " << accountNumber << ", Íîâàÿ ñóììà: " << accounts[accountNumber].balance << std::endl;
    }
    else {
        std::cout << "Ñ÷åò " << accountNumber << " íå ñóùåñòâóåò. Íåâîçìîæíî âûïîëíèòü äåïîçèò." << std::endl;
    }
}

void withdraw(int accountNumber, double amount) {
    if (accounts.find(accountNumber) != accounts.end()) {
        if (accounts[accountNumber].balance >= amount) {
            accounts[accountNumber].balance -= amount;
            std::cout << "Íîìåð ñ÷åòà: " << accountNumber << ", Íîâàÿ ñóììà: " << accounts[accountNumber].balance << std::endl;
        }
        else {
            std::cout << "Íà ñ÷åòå " << accountNumber << " íåäîñòàòî÷íî ñðåäñòâ äëÿ ñíÿòèÿ óêàçàííîé ñóììû." << std::endl;
        }
    }
    else {
        std::cout << "Ñ÷åò " << accountNumber << " íå ñóùåñòâóåò. Íåâîçìîæíî âûïîëíèòü îïåðàöèþ ñíÿòèÿ." << std::endl;
    }
}

void closeAccount(int accountNumber) {
    if (accounts.find(accountNumber) != accounts.end()) {
        accounts.erase(accountNumber);
        std::cout << "Ñ÷åò " << accountNumber << " óñïåøíî çàêðûò." << std::endl;
        std::cout << "Îñòàëîñü îòêðûòûõ ñ÷åòîâ: " << accounts.size() << std::endl;
    }
    else {
        std::cout << "Ñ÷åò " << accountNumber << " íå ñóùåñòâóåò. Íåâîçìîæíî âûïîëíèòü îïåðàöèþ çàêðûòèÿ." << std::endl;
    }
}

void printAllAccounts() {
    std::cout << "Âñå îòêðûòûå ñ÷åòà:" << std::endl;
    for (const auto& account : accounts) {
        std::cout << "Íîìåð ñ÷åòà: " << account.second.accountNumber << ", Áàëàíñ: " << account.second.balance << std::endl;
    }
}

void calculateInterest(double interestRate) {
    std::cout << "Íîâûå ñóììû ñ ó÷åòîì ïðîöåíòíîé ñòàâêè " << interestRate << ":" << std::endl;
    for (auto& account : accounts) {
        double newBalance = account.second.balance * (1 + interestRate / 100);
        std::cout << "Íîìåð ñ÷åòà: " << account.second.accountNumber << ", Íîâàÿ ñóììà: " << newBalance << std::endl;
    }
}

int main() {
    char transactionType;
    double amount;
    int accountNumber;
    double interestRate;

    while (true) {
        std::cout << "Ââåäèòå òèï òðàíçàêöèè (O - îòêðûòü ñ÷åò, B - çàïðîñèòü áàëàíñ, D - äåïîçèò, W - ñíÿòü ñóììó, C - çàêðûòü ñ÷åò, P - ïå÷àòü âñåõ ñ÷åòîâ, I - ïðîöåíòíàÿ ñòàâêà, Q - âûõîä): ";
        std::cin >> transactionType;

        if (transactionType == 'Q') {
            break;
        }

        switch (transactionType) {
        case 'O':
            std::cout << "Ââåäèòå íà÷àëüíûé äåïîçèò: ";
            std::cin >> amount;
            openAccount(amount);
            break;
        case 'B':
            std::cout << "Ââåäèòå íîìåð ñ÷åòà: ";
            std::cin >> accountNumber;
            getBalance(accountNumber);
            break;
        case 'D':
            std::cout << "Ââåäèòå íîìåð ñ÷åòà: ";
            std::cin >> accountNumber;
            std::cout << "Ââåäèòå ñóììó äåïîçèòà: ";
            std::cin >> amount;
            deposit(accountNumber, amount);
            break;
        case 'W':
            std::cout << "Ââåäèòå íîìåð ñ÷åòà: ";
            std::cin >> accountNumber;
            std::cout << "Ââåäèòå ñóììó äëÿ ñíÿòèÿ: ";
            std::cin >> amount;
            withdraw(accountNumber, amount);
            break;
        case 'C':
            std::cout << "Ââåäèòå íîìåð ñ÷åòà: ";
            std::cin >> accountNumber;
            closeAccount(accountNumber);
            break;
        case 'P':
            printAllAccounts();
            break;
        case 'I':
            std::cout << "Ââåäèòå ïðîöåíòíóþ ñòàâêó ïî âêëàäó: ";
            std::cin >> interestRate;
            calculateInterest(interestRate);
            break;
        default:
            std::cout << "Íåâåðíûé òèï òðàíçàêöèè. Ïîïðîáóéòå åùå ðàç." << std::endl;
        }
    }

    return 0;
}



/*äóìàþ, ÷òî äîñòàòî÷íî ñûðî.ìîæíî ûáëî áû äîüàâèòü ïðîâåðêó íà îøèáêè, íî èòàê ÿ íàøëà ñ ïðîøëîé ïàðû â ñîâîåì êîäå î÷åíü ìíîãî îøèáîê....*/


/*ÀÍÍÎÒÀÖÈß:
èñïîëüçóåì ñòðóêòóðó BankAccount, êîòîðàÿ ñîäåðæèò
íîìåð ñ÷åòà è áàëàíñ. Ìû èñïîëüçóåì std::map äëÿ õðàíåíèÿ ñ÷åòîâ, ãäå
íîìåð ñ÷åà ÿâëÿåòñÿ êëþ÷îì, à îáúåêò BankAccount - çíà÷åíèåì.
Ôóíêöèè openAccount, getBalance, deposit, withdraw è closeAccount ðåàëèçóþò
óêàçàííûå îïåðàöèè îòêðûòèÿ ñ÷åòà, çàïðîñà áàëàíñà, äåïîçèòîâ, ñíÿòèé è
çàêðûòèÿ ñ÷åòîâ ñîîòâåòñòâåííî.
Â ôóíêöèÿõ openAccount, deposit è withdraw ìû ïðîâåðÿåì, ñóùåñòâóåò ëè ñ÷åò
ñ óêàçàííûì íîìåðîì. Åñëè ñ÷åò ñóùåñòâóåò, ìû âûïîëíÿåì ñîîòâåòñòâóþùóþ
îïåðàöèþ, èçìåíÿÿ áàëàíñ ñ÷åòà è âûâîäÿ ðåçóëüòàò.
Ôóíêöèÿ printAllAccounts âûâîäèò âñå îòêðûòûå ñ÷åòà è èõ áàëàíñû.
Ôóíêöèÿ calculateInterest ðàñ÷èòûâàåò íîâûé áàëàíñ äëÿ êàæäîãî ñ÷åòà ñ
ó÷åòîì óêàçàííîé ïðîöåíòíîé ñòàâêè.
Â îñíîâíîé ôóíêöèè main ìû çàïðàøèâàåì òèï òðàíçàêöèè ó ïîëüçîâàòåëÿ è
âûïîëíÿåì ñîîòâåòñòâóþùóþ îïåðàöèþ. Ïðè ââîäå òèïà òðàíçàêöèè 'Q'
ïîëüçîâàòåëü ìîæåò âûéòè èç ïðîãðàììû.
Ïðîãðàììà ïðîäîëæàåò ïðèíèìàòü ââîä îò ïîëüçîâàòåëÿ, ïîêà íå áóäåò
ââåäåí òèï òðàíçàêöèè 'Q'.*/