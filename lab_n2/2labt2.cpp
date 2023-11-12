#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <random>

using namespace std;

// Ôóíêöèÿ äëÿ ãåíåðàöèè ñëó÷àéíîãî èìåíè ñòóäåíòà
string generateRandomName()
{
    vector<std::string> names = { "Àëèñà", "Ñîôèÿ", "Ýììà", "Ëèàì", "Íîà", "Ëóêà", "Àìàëèÿ", "Ãåîðãèé", "Ìàêñèì", "Ìèÿ" };

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, names.size() - 1);

    int randomIndex = distribution(generator);

    return names[randomIndex];
}
// Ôóíêöèÿ âûâîäà ñîäåðæèìîãî âåêòîðà ñ èñïîëüçîâàíèåì Range-based for-loop
void printVectorRange(const vector<string>& vec) {
    for (const auto& name : vec) {
        cout << name << " ";
    }
    cout << endl;
}

// Ôóíêöèÿ âûâîäà ñîäåðæèìîãî âåêòîðà ñ èñïîëüçîâàíèåì èòåðàòîðà
void printVectorIterator(const vector<int>& vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// Ôóíêöèÿ âûâîäà ñîäåðæèìîãî âåêòîðà ñ èñïîëüçîâàíèåì èíäåêñíîãî öèêëà
void printVectorIndex(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// Ôóíêöèÿ ðàñ÷åòà ñðåäíåãî çíà÷åíèÿ îöåíîê
double calculateMean(const vector<int>& grades) {
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / grades.size();
}

// Ôóíêöèÿ ðàñ÷åòà ìåäèàíû îöåíîê
double calculateMedian(const vector<int>& grades) {
    vector<int> sortedGrades = grades;
    sort(sortedGrades.begin(), sortedGrades.end());

    if (grades.size() % 2 == 0) {
        int midIndex1 = grades.size() / 2 - 1;
        int midIndex2 = grades.size() / 2;
        return static_cast<double>(sortedGrades[midIndex1] + sortedGrades[midIndex2]) / 2;
    }
    else {
        int midIndex = grades.size() / 2;
        return sortedGrades[midIndex];
    }
}

// Ôóíêöèÿ ðàñ÷åòà ìîäû îöåíîê
vector<int> calculateMode(const vector<int>& grades) {
    map<int, int> counts;
    for (int grade : grades) {
        counts[grade]++;
    }

    int maxCount = 0;
    for (const auto& pair : counts) {
        maxCount = max(maxCount, pair.second);
    }

    vector<int> modeGrades;
    for (const auto& pair : counts) {
        if (pair.second == maxCount) {
            modeGrades.push_back(pair.first);
        }
    }

    return modeGrades;
}

// Ôóíêöèÿ ðàñ÷åòà ìîäû îöåíîê äëÿ ìíîãîìîäàëüíîãî ðàñïðåäåëåíèÿ (Multimodal Mode)
vector<int> calculateMultimodalMode(const vector<int>& grades) {
    map<int, int> counts;
    for (int grade : grades) {
        counts[grade]++;
    }

    int maxCount = 0;
    for (const auto& pair : counts) {
        maxCount = max(maxCount, pair.second);
    }

    vector<int> modeGrades;
    for (const auto& pair : counts) {
        if (pair.second == maxCount) {
            modeGrades.push_back(pair.first);
        }
    }

    // Åñëè ñïèñîê îöåíîê ÿâëÿåòñÿ ìíîãîìîäàëüíûì, ïðîâåðÿåì, åñòü ëè îöåíêè, êîòîðûå
    // âñòðå÷àþòñÿ ðåæå âñåãî. Åñëè òàêèå îöåíêè åñòü, äîáàâëÿåì èõ â ñïèñîê ìîä
    for (const auto& pair : counts) {
        if (pair.second == maxCount - 1) {
            modeGrades.push_back(pair.first);
        }
    }

    return modeGrades;
}

int main() {
    vector<string> names;
    vector<int> grades;

    int option;
    cout << "Âûáåðèòå âàðèàíò èíèöèàëèçàöèè âåêòîðîâ:" << endl;
    cout << "1. Äåìîíñòðàöèîííûé àíàëèç íà äåôîëòíûõ âõîäíûõ çíà÷åíèÿõ" << endl;
    cout << "2. Àíàëèç íà ñëó÷àéíûõ âõîäíûõ çíà÷åíèÿõ" << endl;
    cout << "3. Àíàëèç íà âõîäíûõ çíà÷åíèÿõ îò ïîëüçîâàòåëÿ" << endl;
    cout << "Âûáîð: ";
    cin >> option;

    if (option == 1) {
        // Èíèöèàëèçàöèÿ âåêòîðîâ ñ äåôîëòíûìè çíà÷åíèÿìè
        names = { "Àëèñà", "Ñîôèÿ", "Ýììà", "Ëèàì", "Íîà", "Ëóêà", "Àìàëèÿ", "Ãåîðãèé", "Ìàêñèì", "Ìèÿ" };
        grades = { 95, 80, 75, 90, 85, 92, 88, 79, 87, 93 };
    }
    else if (option == 2) {
        // Èíèöèàëèçàöèÿ âåêòîðîâ ñî ñëó÷àéíûìè çíà÷åíèÿìè
        int n;
        cout << "Ââåäèòå ðàçìåð âûáîðêè: ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            names.push_back(generateRandomName());
            grades.push_back(rand() % 101); // Ãåíåðàöèÿ ñëó÷àéíîé îöåíêè îò 0 äî 100
        }
    }
    else if (option == 3) {
        // Èíèöèàëèçàöèÿ âåêòîðîâ çíà÷åíèÿìè, ââåäåííûìè ïîëüçîâàòåëåì
        int n;
        cout << "Ââåäèòå êîëè÷åñòâî îöåíîê: ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            string name;
            int grade;
            cout << "Ââåäèòå èìÿ äëÿ îöåíêè ¹ " << i + 1 << ": ";
            cin >> name;
            cout << "Ââåäèòå îöåíêó äëÿ " << name << ": ";
            cin >> grade;

            names.push_back(name);
            grades.push_back(grade);
        }
    }
    else {
        cout << "Îøèáêà: íåïðàâèëüíûé âûáîð." << endl;
        return 0;
    }

    cout << endl << "Èìåíà ñòóäåíòîâ:" << endl;
    printVectorRange(names); // Âûâîä èìåí ñ èñïîëüçîâàíèåì Range-based for-loop

    cout << endl << "Îöåíêè ñòóäåíòîâ:" << endl;
    printVectorIterator(grades); // Âûâîä îöåíîê ñ èñïîëüçîâàíèåì èòåðàòîðà

    cout << endl << "Ñðåäíåå çíà÷åíèå îöåíîê: " << calculateMean(grades) << endl;
    cout << "Ìåäèàíà îöåíîê: " << calculateMedian(grades) << endl;

    cout << "Ìîäà îöåíîê: ";
    vector<int> modeGrades = calculateMode(grades);
    printVectorIndex(modeGrades); // Âûâîä ìîäû ñ èñïîëüçîâàíèåì èíäåêñíîãî öèêëà

    cout << endl << "Ìîäà îöåíîê (äëÿ ìíîãîìîäàëüíîãî ðàñïðåäåëåíèÿ): ";
    vector<int> multimodalModeGrades = calculateMultimodalMode(grades);
    printVectorIndex(multimodalModeGrades); // Âûâîä ìîäû äëÿ ìíîãîìîäàëüíîãî ðàñïðåäåëåíèÿ

    return 0;
}