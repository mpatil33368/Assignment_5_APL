Object subclass: #Ride
    instanceVariableNames: 'rideID pickupLocation dropoffLocation distance'.

Ride >> initializeWith: anID pickup: pickup dropoff: dropoff distance: aDistance
    rideID := anID.
    pickupLocation := pickup.
    dropoffLocation := dropoff.
    distance := aDistance.

Ride >> fare
    self subclassResponsibility.

Ride >> rideDetails
    ^ 'Ride ID: ', rideID, 
      ' | From: ', pickupLocation, 
      ' | To: ', dropoffLocation, 
      ' | Distance: ', distance asString, ' miles'.

Ride subclass: #StandardRide
    instanceVariableNames: ''.

StandardRide >> fare
    ^ distance * 1.5.

StandardRide >> rideDetails
    ^ super rideDetails , ' | Type: Standard | Fare: $', self fare asString.

Ride subclass: #PremiumRide
    instanceVariableNames: ''.

PremiumRide >> fare
    ^ distance * 3.

PremiumRide >> rideDetails
    ^ super rideDetails , ' | Type: Premium | Fare: $', self fare asString.

Object subclass: #Driver
    instanceVariableNames: 'driverID name rating assignedRides'.

Driver >> initializeWith: anID name: aName rating: aRating
    driverID := anID.
    name := aName.
    rating := aRating.
    assignedRides := OrderedCollection new.

Driver >> addRide: aRide
    assignedRides add: aRide.

Driver >> getDriverInfo
    | info |
    info := 'Driver ID: ', driverID, ' | Name: ', name, ' | Rating: ', rating asString, Character lf.
    assignedRides do: [:r | info := info , r rideDetails , Character lf ].
    ^ info.

Object subclass: #Rider
    instanceVariableNames: 'riderID name requestedRides'.

Rider >> initializeWith: anID name: aName
    riderID := anID.
    name := aName.
    requestedRides := OrderedCollection new.

Rider >> requestRide: aRide
    requestedRides add: aRide.

Rider >> viewRides
    | output |
    output := 'Rider ', name, ' Ride History:', Character lf.
    requestedRides do: [:r | output := output , r rideDetails , Character lf ].
    ^ output.

