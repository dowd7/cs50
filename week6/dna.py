import csv
import sys


def main():

    # TODO: Check for command-line usage
    if (len(sys.argv) != 3):
        print("Usage: 2 command arguments")
        sys.exit(1)

    # TODO: Read database file into a variable
    database = sys.argv[1]

    rows = []
    with open(database) as file:
        reader = csv.DictReader(file)
        names = reader.fieldnames
        for row in reader:
            rows.append(row)

    # print(names)
    # print(rows)
    # TODO: Read DNA sequence file into a variable
    text = sys.argv[2]
    sequence = open(text, "r")
    sequence = sequence.read()
    # print(sequence)

    # TODO: Find longest match of each STR in DNA sequence
    matches = {}
    for i in range(1, len(names)):
        matches[names[i]] = longest_match(sequence, names[i])

    # TODO: Check database for matching profiles
    # print(matches)

    for entry in rows:
        for i in range(1, len(names)):
            if int(entry[names[i]]) != matches[names[i]]:
                break
        else:
            print(entry['name'])
            return
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
