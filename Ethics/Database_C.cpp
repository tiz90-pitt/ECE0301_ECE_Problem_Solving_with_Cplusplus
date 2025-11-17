#include "Database.hpp"
#include <algorithm>

// Default constructor: initializes the number of entries to 0
Database::Database() : num_entries(0) {}

// Constructor with one Entry: adds the entry and updates num_entries
Database::Database(const Entry& entry) : num_entries(1) {
    data.push_back(entry);
}

// Constructor with a vector of Entries: adds all entries and updates num_entries
Database::Database(const std::vector<Entry>& entries) : num_entries(entries.size()), data(entries) {}

// Add method: adds a new entry if ID is unique, else returns false
bool Database::add(const Entry& entry) {
    if (search(entry.id)) return false;
    data.push_back(entry);
    ++num_entries;
    return true;
}

// Remove method: removes entry by id, returns true if found and removed
bool Database::remove(int id) {
    auto it = std::find_if(data.begin(), data.end(), [id](const Entry& entry) {
        return entry.id == id;
    });
    if (it != data.end()) {
        data.erase(it);
        --num_entries;
        return true;
    }
    return false;
}

// Size method: returns the number of entries
int Database::size() const {
    return num_entries;
}

// is_empty method: checks if database is empty
bool Database::is_empty() const {
    return num_entries == 0;
}

// Search method: checks if an entry with the specified ID exists
bool Database::search(int id) const {
    return std::any_of(data.begin(), data.end(), [id](const Entry& entry) {
        return entry.id == id;
    });
}

// get_all_entries method: returns a copy of the data vector
std::vector<Entry> Database::get_all_entries() const {
    return data;
}

// sort_by_id method: sorts by id in ascending or descending order
void Database::sort_by_id(bool ascending) {
    if (ascending) {
        std::sort(data.begin(), data.end(), [](const Entry& a, const Entry& b) {
            return a.id < b.id;
        });
    } else {
        std::sort(data.begin(), data.end(), [](const Entry& a, const Entry& b) {
            return a.id > b.id;
        });
    }
}

// sort_by_name method: sorts entries alphabetically by name
void Database::sort_by_name() {
    std::sort(data.begin(), data.end(), [](const Entry& a, const Entry& b) {
        return a.name < b.name;
    });
}

// search_criteria method: returns ID of the first entry meeting the criteria or -1
int Database::search_criteria(double upper[3]) const {
    for (const auto& entry : data) {
        if (entry.max_delay <= upper[0] &&
            entry.power_per_unit <= upper[1] &&
            entry.bulk_price <= upper[2]) {
            return entry.id;
        }
    }
    return -1;
}
