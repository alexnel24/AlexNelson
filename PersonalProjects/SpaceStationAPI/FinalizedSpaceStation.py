from Functions import SpaceStationAPIResponse
from Functions import peopleCurrentlyInSpace
from Functions import namesOfThoseInSpace
from Functions import printOverheadList

# here my functions are put together in a format that takes user input
print("running")
spaceResponse = SpaceStationAPIResponse()
print("number of people currently in space: " + str(peopleCurrentlyInSpace(spaceResponse)))
spaceResponse = SpaceStationAPIResponse()
print(namesOfThoseInSpace(spaceResponse))

print("\nEnter your coordinates: ")
lat = input("Latitude:")
lon = input("Longitude:")
print("")
printOverheadList(lat, lon)


