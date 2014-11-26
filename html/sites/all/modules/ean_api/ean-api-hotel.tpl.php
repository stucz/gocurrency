<?php
/**
 * This template used for render one hotel item
 *
 * @var $hotel array contains hotel info
 * Possible keys
 * - hotelId  long  ID for the property. This same ID will be used in any subsequent room or reservation requests.
 * - name  string  Name of the hotel
 * - address1  string  Hotel street address
 * - city  string  Hotel city
 * - stateProvinceCode  string  Two character code for the state/province containing the specified city. Returns only for US, CA, and AU country codes.
 * - countryCode  string  Two character ISO-3166 code for the country the hotel is located in
 * - postalCode  string  Postal code for the hotel
 * - airportCode  string  Airport code associated with the hotel
 * - supplierType  string  Supplier of the hotel. This same supplier will be used to process any reservations placed.
 * - propertyCategory  string  The category of the property returned.
 *      1: hotel
 *      2: suite
 *      3: resort
 *      4: vacation rental/condo
 *      5: bed & breakfast
 *      6: all-inclusive
 * - hotelRating  float  Star rating of the hotel. A value of 0.0 or a blank value indicate none is available.
 * - amenityMask  long  See details on hotel amenity masks
 * - shortDescription  string  Short description text entered by the property. Truncated if entry exceeds 200 characters.
 * - locationDescription  string  General location as entered by the property, e.g. "Near Pike Place Market"
 * - lowRate  string  Lowest rate returned by the hotel in recent queries. This is a statistical figure and not necessarily a rate for current availability.
 * - highRate  string  Highest rate returned by the hotel in recent queries. This is a statistical figure and not necessarily a rate for current availability.
 * - rateCurrencyCode  string  Currency code of the high or low rates returned.
 * - latitude  float  Latitude coordinate for the hotel.
 * - longitude  float  Longitude coordinate for the hotel.
 * - proximityDistance  float  The distance of the hotel from the originally specified origin coordinates, if that search method was used.
 * - proximityUnit  string  Unit for the distance provided by proximityDistance. MI or KM.
 * - hotelInDestination  boolean  Indicates whether the property is within the originally specified city or in an expanded area, i.e. a major suburb or other nearby city.
 * - thumbNailUrl  string  URL path of a thumbnail image of the property, if provided.
 * - deepLink  string  Deep link into the corresponding hotel page on your template, used if you are creating a hybrid site.
 * - RoomRateDetailsList  container for RoomRate Details array  Container only, no attributes. Element and all contents return for Expedia Collect only.
 */
?>

<tr><td class="hotel-item">
  <?php echo l($hotel['name'], $hotel['deepLink'], array('target' => '_blank')); ?>
</td><td class="hotel-rating">
  <?php echo $hotel['hotelRating']; ?>
</td></tr>
