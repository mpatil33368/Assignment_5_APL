#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Ride {
protected:
    string rideID;
    string pickupLocation;
    string dropoffLocation;
    double distance;

public:
    Ride(string id, string pickup, string dropoff, double dist)
        : rideID(id), pickupLocation(pickup), dropoffLocation(dropoff), distance(dist) {}

    virtual double fare() const = 0; // Pure virtual
    virtual void rideDetails() const {
        cout << "Ride ID: " << rideID << ", From: " << pickupLocation << ", To: " << dropoffLocation << ", Distance: " << distance << " miles\n";
    }

    virtual ~Ride() {}
};

class StandardRide : public Ride {
public:
    StandardRide(string id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    double fare() const override {
        return distance * 1.5; // $1.5 per mile
    }

    void rideDetails() const override {
        Ride::rideDetails();
        cout << "Type: Standard, Fare: $" << fare() << endl;
    }
};

class PremiumRide : public Ride {
public:
    PremiumRide(string id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    double fare() const override {
        return distance * 3.0; // $3 per mile
    }

    void rideDetails() const override {
        Ride::rideDetails();
        cout << "Type: Premium, Fare: $" << fare() << endl;
    }
};

class Driver {
private:
    string driverID;
    string name;
    float rating;
    vector<Ride*> assignedRides;

public:
    Driver(string id, string n, float r) : driverID(id), name(n), rating(r) {}

    void addRide(Ride* ride) {
        assignedRides.push_back(ride);
    }

    void getDriverInfo() const {
        cout << "Driver ID: " << driverID << ", Name: " << name << ", Rating: " << rating << endl;
        cout << "Assigned Rides:\n";
        for (auto ride : assignedRides) {
            ride->rideDetails();
        }
    }
};

class Rider {
private:
    string riderID;
    string name;
    vector<Ride*> requestedRides;

public:
    Rider(string id, string n) : riderID(id), name(n) {}

    void requestRide(Ride* ride) {
        requestedRides.push_back(ride);
    }

    void viewRides() const {
        cout << "Rider: " << name << "'s Rides:\n";
        for (auto ride : requestedRides) {
            ride->rideDetails();
        }
    }
};

// Example usage
int main() {
    Rider r1("R001", "Alice");
    Driver d1("D001", "Bob", 4.8);

    Ride* ride1 = new StandardRide("RID100", "Downtown", "Uptown", 5);
    Ride* ride2 = new PremiumRide("RID101", "Airport", "Hotel", 10);

    r1.requestRide(ride1);
    r1.requestRide(ride2);

    d1.addRide(ride1);
    d1.addRide(ride2);

    r1.viewRides();
    cout << endl;
    d1.getDriverInfo();

    delete ride1;
    delete ride2;

    return 0;
}
