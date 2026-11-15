SELECT description
    FROM crime_scene_reports
   WHERE year = 2021
    AND month = 7
    AND day = 28
    AND street = 'Humphrey street';

SELECT name, transcript
    FROM interviews
    WHERE year = 2021
    AND month = 7
    AND day = 28

SELECT name
    FROM people
    WHERE name = 'Eugene';

SELECT account_number, amount
    FROM atm_transactions
 WHERE year = 2021
    AND month = 7
    AND day = 28
    AND atm_location = 'leggett street'
    AND transaction_type = 'withdraw'
