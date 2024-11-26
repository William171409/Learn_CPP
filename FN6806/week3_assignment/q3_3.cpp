#include <iostream>
#include "q3_3.hpp"

using namespace std;


int main() {
    Photo photo1("BeachSunset");
    Photo photo2("MountainPeak");
    Photo photo3("CityLights");
    
    photo1.add_tag("vacation");
    photo1.add_tag("sunset");
    photo2.add_tag("vacation");
    photo2.add_tag("mountain");
    photo3.add_tag("city");
    photo3.add_tag("night");

    PhotoAlbum album1("SummerVacation");
    album1.add_photo(photo1);
    album1.add_photo(photo2);
    
    PhotoAlbum album2("UrbanExploration");
    album2.add_photo(photo3);

    PhotoApp app;
    app.add_album(album1);  
    app.add_album(album2);

    // Search by tag
    app.search_by_tag("vacation");
    cout<<'\n';
    // Search by name
    app.search_by_name("BeachSunset");

    album1.delete_photo("BeachSunset");
    cout << "\nAfter deleting 'BeachSunset' from album 'SummerVacation':\n";
    album1.display();

    app.delete_album("UrbanExploration");
    cout << "\nAfter deleting album 'UrbanExploration':\n";
    app.search_by_tag("night");

    return 0;
}
