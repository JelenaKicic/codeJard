#include "../Include/event.h"

//pomocna funkcija za ispitivanje izbranog kriterijuma i citanje odgovarajucih dogadjaja
void checkOverviewCriteria(int overviewCriteria, Event **events)
{
    std::ifstream file("./Database/events.txt");

    int i = 0;
    std::string line, name, description, city, address, type, dayStr, monthStr, yearStr, hoursStr, minutesStr;
    int day, month, year, hours, minutes;

    while (getline(file, line))
    {
        std::stringstream lineStream(line);

        getline(lineStream, name, '|');
        std::cout << "aaaaaaaaaaaaaaaaaaa" << name;
        // events[i](name, description, city, address, type, day, month, year, hours, minutes);
    }
}

void sortEvents(int sortCriteria, int sortDirection, Event **events)
{
}

//prikaz dogadjaja po izabranom redu i kriterijumu
void geteventsByOrder(int overviewCriteria, int sortCriteria, int sortDirection)
{
    Event **events;

    checkOverviewCriteria(overviewCriteria, events);

    sortEvents(sortCriteria, sortDirection, events);
}

//izbor kriterijuma pretrage i nacina na koji ce dogadjaji biti sortirani
void eventOverviewCriteria()
{
    int overviewCriteria = 0, sortCriteria = 0, sortDirection = 0;
    std::cout << "Izaberite kritrijum pregleda dogadjaja:" << std::endl
              << "1. Pregled danasnjih dogadjaja" << std::endl
              << "2. Pregled svih buducih dogadjaja" << std::endl
              << "3. Pregled dogadjaja odredjene kategorije" << std::endl
              << "4. Pregled dogadjaja koji su prosli" << std::endl;

    do
    {
        std::cout << "Unesi broj:" << std::endl;
        std::cin >> overviewCriteria;
    } while (overviewCriteria < 1 || overviewCriteria > 4);

    std::cout << "Sortiraj dogadjaje po:" << std::endl
              << "1. Nazivu" << std::endl
              << "2. Lokaciji" << std::endl
              << "3. Vrsti dogadjaja (kategorija)" << std::endl
              << "4. Datumu i vremenu odrzavanja" << std::endl;

    do
    {
        std::cout << "Unesi broj:" << std::endl;
        std::cin >> sortCriteria;
    } while (sortCriteria < 1 || sortCriteria > 4);

    std::cout << "Sortiranje vrisiti po:" << std::endl
              << "1. Opadajucem" << std::endl
              << "2. Rastucem" << std::endl
              << "poretku." << std::endl;

    do
    {
        std::cout << "Unesi broj:" << std::endl;
        std::cin >> sortDirection;
    } while (sortDirection < 1 || sortDirection > 2);

    geteventsByOrder(overviewCriteria, sortCriteria, sortDirection);
}

Event::Event()
{
    setName("");
    setDescription("");
    setLocation("", "");
    setType("");
    setDate(1, 1, 2020);
    setTime(0, 0);
}

Event::Event(std::string name, std::string description, std::string city, std::string address, std::string type, int day, int month, int year, int hours, int minutes)
{
    setName(name);
    setDescription(description);
    setLocation(city, address);
    setType(type);
    setDate(day, month, year);
    setTime(hours, minutes);
}

void Event::setName(std::string name)
{
    this->name = name;
}

void Event::setDescription(std::string description)
{
    this->description = description;
}

void Event::setType(std::string type)
{
    this->type = type;
}

void Event::setLocation(std::string city, std::string address)
{
    this->location.setCity(city);
    this->location.setAddress(address);
}

void Event::setTime(int hours, int minutes)
{
    this->time.setHours(hours);
    this->time.setMinutes(minutes);
}

void Event::setDate(int day, int month, int year)
{
    this->date.setDate(day, month, year);
}
