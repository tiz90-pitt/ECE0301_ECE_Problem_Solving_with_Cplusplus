#include "Database.hpp"

//defauilt constructor
Database::Database() : num_entries(0) {}

//constructor w/ 1 entry
Database::Database(const Entry& entry) : num_entries(1){
    data_entries.push_back(entry);
}

//constructor with vector entries
Database::Database(const std::vector<Entry>& entries) : data_entries(entries), num_entries(entries.size()) {}


//add entry 
bool Database::add(const Entry& entry) {
    //check if entry with same id exists
    for(const auto& existingEntry : data_entries){
        if (existingEntry.id == entry.id){
            return false; 
        }
    }
    //No entry with same id
    data_entries.push_back(entry);
    num_entries++;
    return true; //
}

//remove entry based on id
bool Database::remove(int id){
    //sort through database to find entry with matching id
    for(auto it = data_entries.begin(); it != data_entries.end(); ++it){
        if(it->id == id){
            data_entries.erase(it); //remove
            num_entries--; //update number of entries 
            return true; //bc successful remove
        }
    }
    return false; //id not found
}

//get number of entries
int Database::size() const {
    return num_entries; 
}

//Check if database is empty
bool Database::is_empty() const{
    if(num_entries==0){
        return true;
    }
    return false;
}

//search database via id
bool Database::search(int id) const {
    for(const auto& entry : data_entries){
        if(entry.id == id){
            return true; //entry w/ id found
        }
    }
    return false; //entry w/ id not found
}

//get all entries from databse
std::vector<Entry> Database::get_all_entries() const {
    //std::vector<Entry> emptyVector;
    return data_entries;
}

//sort database by id
void Database::sort_by_id(bool ascending) {
    int n = data_entries.size();
    for (int i = 0; i < n; ++i){
        for(int j = 0; j < n-i-1; ++j){
            if ((ascending && data_entries[j].id > data_entries[j + 1].id) || (!ascending && data_entries[j].id < data_entries[j+1].id)){
                std::swap(data_entries[j], data_entries[j+1]);
            }
        }
    }

}