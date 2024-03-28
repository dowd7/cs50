--theft took place on July 28, 2023 and that it took place on Humphrey Street
select description from crime_scene_reports
where day = 28 and month = 07 and year = 2023 and street = 'Humphrey Street';

--295: Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
--Interviews were conducted today with three witnesses who were present at the
--time – each of their interview transcripts mentions the bakery.

select name, transcript from interviews where day = 28 and month = 07 and year = 2023;

--Sometime within ten minutes of the theft, I saw the thief get into a car in
--the bakery parking lot and drive away. If you have security footage from the
-- bakery parking lot, you might want to look for cars that left the parking lot
--in that time frame.

select license_plate from bakery_security_logs
 where day = 28 and month = 07 and year = 2023 and hour = 10 and minute between 15 and 25;

select name from people where license_plate in (select license_plate from bakery_security_logs
 where day = 28 and month = 07 and year = 2023 and hour = 10 and minute between 15 and 25);


--Earlier this morning, before I arrived at Emma's bakery, I was walking by the
-- ATM on Leggett Street and saw the thief there withdrawing some money.

select account_number from atm_transactions
 where day = 28 and month = 07 and year = 2023 and atm_location = 'Leggett Street';

 select name from people join bank_accounts on people.id = bank_accounts.person_id
  where bank_accounts.account_number in (select account_number from atm_transactions
  where day = 28 and month = 07 and year = 2023 and atm_location = 'Leggett Street');

--As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
--I heard the thief say that they were planning to take the earliest flight out
-- of Fiftyville tomorrow. The thief then asked the person on the other end of the
 -- phone to purchase the flight ticket.

select caller from phone_calls where
 day = 28 and month = 07 and year = 2023 and duration < 60;

select name from people where phone_number in (select caller from phone_calls where
 day = 28 and month = 07 and year = 2023 and duration < 60);

SELECT city FROM airports
 WHERE id IN (
    SELECT destination_airport_id FROM flights WHERE year = 2023 AND month = 7 AND day = 29
    ORDER BY hour, minute ASC LIMIT 1
);
