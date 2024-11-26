#pragma once

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

class Photo {
public:
    string name;
    unordered_set<string> tags;  
    
    Photo(string name) : name(name) {}

    // Add a tag to the photo
    void add_tag(const string& tag) {
        tags.insert(tag);
    }

    // Delete a tag from the photo
    void delete_tag(const string& tag) {
        tags.erase(tag);
    }
    
    // Display photo details
    void display() const {
        cout << "Photo(name=" << name << ", tags=[";
        for (auto it = tags.begin(); it != tags.end(); ++it) {
            if (it != tags.begin()) cout << ", ";
            cout << *it;
        }
        cout << "])" << endl;
    }
};

class PhotoAlbum {
public:
    string name;
    vector<Photo> photos;  
    
    PhotoAlbum(string name) : name(name) {}

    // Add a photo to the album
    void add_photo(const Photo& photo) {
        photos.push_back(photo);
    }

    // Delete a photo from the album by its name
    void delete_photo(const string& photo_name) {
        for (auto it = photos.begin(); it != photos.end(); ++it) {
            if (it->name == photo_name) {
                photos.erase(it);
                break;
            }
        }
    }

    // Display album details
    void display() const {
        cout << "Album(name=" << name << ", photos=[";
        for (auto& photo : photos) {
            photo.display();
        }
        cout << "])" << endl;
    }
};

// PhotoApp class
class PhotoApp {
public:
    unordered_map<string, PhotoAlbum> albums;  
    
    // Add an album to the app using emplace
    void add_album(const PhotoAlbum& album) {
        albums.emplace(album.name, album);  // Using emplace to add the album
    }

    // Delete an album from the app by its name
    void delete_album(const string& album_name) {
        albums.erase(album_name);
    }

    // Search for photos by tag across all albums
    void search_by_tag(const string& tag) const {
        bool found = false;
        for (auto& album_entry : albums) {
            for (auto& photo : album_entry.second.photos) {
                if (photo.tags.find(tag) != photo.tags.end()) {
                    if (!found) {
                        cout << "Photos with tag '" << tag << "':\n";
                        found = true;
                    }
                    photo.display();
                }
            }
        }
        if (!found) {
            cout << "No photos found with tag '" << tag << "'." << endl;
        }
    }

    // Search for a photo by its name across all albums
    void search_by_name(const string& photo_name) const {
        bool found = false;
        for (auto& album_entry : albums) {
            for (auto& photo : album_entry.second.photos) {
                if (photo.name == photo_name) {
                    if (!found) {
                        cout << "Photo with name '" << photo_name << "':\n";
                        found = true;
                    }
                    photo.display();
                }
            }
        }
        if (!found) {
            cout << "No photo found with name '" << photo_name << "'." << endl;
        }
    }
};
