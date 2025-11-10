#ifndef _DATABASE_HPP
#define _DATABASE_HPP

#include <string>
#include <vector>

struct Entry
{
    int id;
    std::string name;
    int units, pins, transistors;
    double max_delay, power_per_unit, bulk_price;
};

// Database class declaration below
class Database
{
private:
    int num_entries;
    std::vector<Entry> data;

public:
    // default constructor
    Database(); // A

    Database(const Entry& entry);
    Database(const std::vector<Entry>& entries);
    // other public functions go here
    bool add(const Entry& entry);
    bool remove(int id);
    int size() const;
    bool is_empty() const;
    bool search(int id) const;
    std::vector<Entry> get_all_entries() const;
    void sort_by_id(bool ascending = true);

    void sort_by_name(); // K
    int search_criteria(double upper[3]) const; // L
};

#endif
