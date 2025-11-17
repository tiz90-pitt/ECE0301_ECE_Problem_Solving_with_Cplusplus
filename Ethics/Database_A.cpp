#include "Database.hpp"

// Default constructor
Database::Database() : numE(0) {
    // Initialize the number of entries to 0
}

// Constructor with Entry argument
Database::Database(const Entry& entry) : numE(1) {
    // Initialize the number of entries to 1
    databaseData.push_back(entry); // Adding the entry to the database
}

// Constructor with Vector of Entries argument
Database::Database(const std::vector<Entry>& entries) : databaseData(entries), numE(entries.size()) {
    
}

//Methods:

// Method to add an entry to the database
bool Database::add(const Entry& entry) {
    // Checking if an entry with the same id already exists
    for (const auto& e : databaseData) {
        if (e.id == entry.id) {
            return false; 
        }
    }

    databaseData.push_back(entry); // Add the entry to the database
    numE++; // Update the number of entries
    return true; 
}

// Method to remove an entry from the database
bool Database::remove(int id) {
    for (auto it = databaseData.begin(); it != databaseData.end(); ++it) {
        if (it->id == id) {
            databaseData.erase(it); // Remove the entry
            numE--; // Update the number of entries
            return true;
        }
    }
    return false; // if the entry was not found
}

// Method to get the number of entries in the database
int Database::size() const {
    return numE; 
}

// Method to check if the database is empty
bool Database::is_empty() const {
    return numE == 0; // true if the database is empty
}

// Method to search for an entry by its id
bool Database::search(int id) const {
    for (const auto& entry : databaseData) {
        if (entry.id == id) {
            return true; 
        }
    }
    return false; 
}

// Method to get all entries from the database
std::vector<Entry> Database::get_all_entries() const {
    return databaseData; 
}

// Method to sort entries by id
void Database::sort_by_id(bool ascending) {
    int n = databaseData.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if ((ascending && databaseData[j].id > databaseData[j + 1].id) ||
                (!ascending && databaseData[j].id < databaseData[j + 1].id)) {
                // Swaps if the entries are in the wrong order
                std::swap(databaseData[j], databaseData[j + 1]);
            }
        }
    }
}
