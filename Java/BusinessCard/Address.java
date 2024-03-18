public class Address {
    private final String zipCode;
    private final String city;
    private final String street;
    private final String houseNumber;
    public Address(String zipCode, String city, String street, String houseNumber){
        this.zipCode = zipCode;
        this.city = city;
        this.street = street;
        this.houseNumber = houseNumber;
    }
    public static Address of(String stringAddress){
        String[] stringSplit = stringAddress.split(" ", -1);
        String zipCode = stringSplit[2];
        String city = stringSplit[3];
        String street = stringSplit[0];
        String houseNumber = stringSplit[1];
        return new Address(zipCode, city, street, houseNumber);
    }

    @Override
    public String toString(){
        return street + " " + houseNumber + ", " + zipCode + " " + city;
    }
    public String getCity() {
        return city;
    }

    public String getHouseNumber() {
        return houseNumber;
    }

    public String getStreet() {
        return street;
    }

    public String getZipCode() {
        return zipCode;
    }
}
