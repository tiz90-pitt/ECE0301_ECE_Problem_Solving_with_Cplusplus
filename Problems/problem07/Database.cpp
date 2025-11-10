#include "Database.hpp"

// initialize empty data
Database::Database() : num_entries(0) {}

// initialize with one row of Entry
Database::Database(const Entry& entry) : num_entries(0) {
  add(entry);
}

// initialize with vector
Database::Database(const std::vector<Entry>& entries) : num_entries(0) {
  for (const auto& entry : entries) {
    add(entry);
  }
}

// add function
bool Database::add(const Entry& entry) {
  if (search(entry.id)) { // Search func to check copies
    return false; // False when copy ID is found
  }
  data.push_back(entry); // append entry
  num_entries++; // size increased
  return true;
}

// remove function
bool Database::remove(int id) {
  for (int i = 0; i < data.size(); i++) {
    if (data[i].id == id) {
      data.erase(data.begin() + i);
      num_entries--; // size - 1
      return true;
    }
  }
  return false;
}

// size function
int Database::size() const {
  return num_entries;
}

// is_empty function
bool Database::is_empty() const {
  if (num_entries == 0) {
    return true;
  }
  else {
    return false;
  }
}

// search function
bool Database::search(int id) const {
  for (const auto& entry : data) {
    if (entry.id == id) {
      return true;
    }
  }
  return false;
}

// get_all_entries function
std::vector<Entry> Database::get_all_entries() const {
  return data;
}

// sort_by_id function
void Database::sort_by_id(bool ascending) {
  for (int i = 0; i < num_entries - 1; i++) {
    for (int j = 0; j < num_entries - 1; j++) {
      bool swap = false;

      if (ascending) {
        if (data[j].id > data[j+1].id) { // Asc order
          swap = true;
        }
      }
      else {
        if (data[j].id < data[j+1].id) { // Desc order
          swap = true;
        }
      }
      if (swap) {
        std::swap(data[j], data[j+1]);
      }
    }
  }
}

// sort_by_name function
void Database::sort_by_name() {
  for (int i = 0; i < num_entries - 1; i++) {
    for (int j = 0; j < num_entries - 1; j++) {
      if (data[j].name > data[j+1].name) { // Comparing the first letters of ASCII are in Alphabetical order
        std::swap(data[j], data[j+1]);
      }
    }
  }
}

// search_criteria function
int Database::search_criteria(double upper[3]) const {
// max_delay <= upper[0], 
// power_per_unit <= upper[1],
// bulk_price <= upper[2]
  for (const auto& entry : data) {
    if (entry.max_delay <= upper[0] && entry.power_per_unit <= upper[1] && entry.bulk_price <= upper[2]) {
      return entry.id;
    }
  }
  return 0;
}
