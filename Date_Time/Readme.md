# Java Data & Time

## Package java.time

`java.time` is the main API for dates, times, instants, and durations.

The classes defined here represent the principle date-time concepts, including instants, durations, dates, times, time-zones and periods. They are based on the ISO calendar system. All the classes are immutable and thread-safe.

### Date and Times

`Instant` is essentially a numeric timestamp. The current Instant can be retrieved from a `Clock`. This is useful for logging and persistence of a point in time and has in the past been associated with storing the result from System.currentTimeMillis().

`LocalDate:` it stores a date without a time. This stores a date like '2010-12-03' and could be used to store a date of birth..

`LocalTime:` it stores a time without a date. this stores a time like '12:45' and could be used to store an opening or closing time.

`LocalDateTime:` it stores a date and time. this stores a date-time like '2010-12-10T12:45'.

`ZonedDateTime:` stores a date and time with a time-zone. This is useful if we want to perform accurate calculations of dates and times taking into account the ZonId.

### Duration and Period

Beyond dates and times, the API also allows the storage of periods and durations of time. A Duration is a simple measure of time along the time-line in nanoseconds. A Period expresses an amount of time in units meaningful to humans, such as years or days.

### Additional Value types

**`Months:`** it stores a month on its own. This stores a single month-of-year in isolation, such as "DECEMBER".

**`DayofWeek:`** it stores a day-of-week on its own. This stores a single day-of-week in isolation, such as 'TUESDAY'.

**`Year:`** it stores a year on its own. This stores a single year in isolation, such as `2022`.

**`YearMonth:`** it stores a year and month without a day or time. This stores a single year in isolation, such as '2022-29' and could be used for a credit card expiry.

**`MonthDay:`** it stores a month and day without a year or time. This stores a month and day-of-month, such as '--08-23' and could be used to store an annual event like a birthday, festival date without storing the year.

**`OffsetTime:`** it stores a time and offset from UTC without a date. This stores a date like _'07:45+05:00_'. The ZoneOffset is of the form _'+05:00'_.

**`OffsetDateTime:`** it stores a date and time and offset from UTC. this stores a date-time like _'2022-12-21T07:45+05:00'_. This is sometime found in XML messages and other forms of persistence, but contains less information than a full time-zone.

### Classes and Interfaces

`Clock:`
- A clock providing access to the current instant, date and time using a time-zone.

`DateTimeException:`
- Exception used to indicate a problem while calculating a date-time.

`DayOfWeek:`
- A day-of-week, such as 'Tuesday'.

`Duration:`
- A time-based amount of time, such as '34.5 seconds'.

`Instant:`
- An instantaneous point on the time-line.

`InstantSource:`
- Provides access to the current instant.

`LocalDate:`
- A date without a time-zone in the ISO-8601 calendar system, such as 2007-12-03.

`LocalDateTime:`
- A date-time without a time-zone in the ISO-8601 calendar system, such as 2007-12-03T10:15:30.

`LocalTime:`
- A time without a time-zone in the ISO-8601 calendar system, such as 10:15:30.

`Month:`
- A month-of-year, such as 'July'.

`MonthDay:`
- A month-day in the ISO-8601 calendar system, such as --12-03.

`OffsetDateTime:`
- A date-time with an offset from UTC/Greenwich in the ISO-8601 calendar system, such as 2007-12-03T10:15:30+01:00.

`OffsetTime:`
- A time with an offset from UTC/Greenwich in the ISO-8601 calendar system, such as 10:15:30+01:00.

`Period:`
- A date-based amount of time in the ISO-8601 calendar system, such as '2 years, 3 months and 4 days'.

`Year:`
- A year in the ISO-8601 calendar system, such as 2007.

`YearMonth:`
- A year-month in the ISO-8601 calendar system, such as 2007-12.

`ZonedDateTime:`
- A date-time with a time-zone in the ISO-8601 calendar system, such as 2007-12-03T10:15:30+01:00 Europe/Paris.

`ZoneId:`
- A time-zone ID, such as Europe/Paris.

`ZoneOffset:`
- A time-zone offset from Greenwich/UTC, such as +02:00.