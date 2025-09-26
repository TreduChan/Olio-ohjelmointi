#include <stdio.h>
#include <stdlib.h>

/* Length conversions */
double meters_to_kilometers(double meters) { return meters / 1000.0; }
double kilometers_to_meters(double kilometers) { return kilometers * 1000.0; }
double kilometers_to_miles(double kilometers) { return kilometers * 0.621371; }
double miles_to_kilometers(double miles) { return miles * 1.60934; }
double meters_to_miles(double meters) { return kilometers_to_miles(meters / 1000.0); }
double miles_to_meters(double miles) { return miles_to_kilometers(miles) * 1000.0; }

/* Weight conversions */
double kilograms_to_pounds(double kilograms) { return kilograms * 2.20462; }
double pounds_to_kilograms(double pounds) { return pounds / 2.20462; }

/* Temperature conversions */
double celsius_to_fahrenheit(double celsius) { return celsius * 9.0 / 5.0 + 32.0; }
double fahrenheit_to_celsius(double fahrenheit) { return (fahrenheit - 32.0) * 5.0 / 9.0; }

/* Print results */
void print_length_result(char source_unit, char target_unit, double input_value, double result_value)
{
    if (source_unit == '1')
        printf("%.2f Meters: ", input_value);
    if (source_unit == '2')
        printf("%.2f Kilometres: ", input_value);
    if (source_unit == '3')
        printf("%.2f Miles: ", input_value);

    if (target_unit == '1')
        printf("%.2f Meters\n", result_value);
    if (target_unit == '2')
        printf("%.2f Kilometres\n", result_value);
    if (target_unit == '3')
        printf("%.2f Miles\n", result_value);
}

void print_weight_result(char source_unit, char target_unit, double input_value, double result_value)
{
    if (source_unit == '1')
        printf("%.2f Kilograms: ", input_value);
    if (source_unit == '2')
        printf("%.2f Pounds: ", input_value);

    if (target_unit == '1')
        printf("%.2f Kilograms\n", result_value);
    if (target_unit == '2')
        printf("%.2f Pounds\n", result_value);
}

void print_temp_result(char source_unit, char target_unit, double input_value, double result_value)
{
    if (source_unit == '1')
        printf("%.2f Celsius: ", input_value);
    if (source_unit == '2')
        printf("%.2f Fahrenheit: ", input_value);

    if (target_unit == '1')
        printf("%.2f Celsius\n", result_value);
    if (target_unit == '2')
        printf("%.2f Fahrenheit\n", result_value);
}

/* Conversion dispatch */
double convert_length(char source_unit, char target_unit, double input_value)
{
    if (source_unit == target_unit)
        return input_value;
    if (source_unit == '1' && target_unit == '2')
        return meters_to_kilometers(input_value);
    if (source_unit == '2' && target_unit == '1')
        return kilometers_to_meters(input_value);
    if (source_unit == '2' && target_unit == '3')
        return kilometers_to_miles(input_value);
    if (source_unit == '3' && target_unit == '2')
        return miles_to_kilometers(input_value);
    if (source_unit == '1' && target_unit == '3')
        return meters_to_miles(input_value);
    if (source_unit == '3' && target_unit == '1')
        return miles_to_meters(input_value);
    return input_value;
}

double convert_weight(char source_unit, char target_unit, double input_value)
{
    if (source_unit == target_unit)
        return input_value;
    if (source_unit == '1' && target_unit == '2')
        return kilograms_to_pounds(input_value);
    if (source_unit == '2' && target_unit == '1')
        return pounds_to_kilograms(input_value);
    return input_value;
}

double convert_temp(char source_unit, char target_unit, double input_value)
{
    if (source_unit == target_unit)
        return input_value;
    if (source_unit == '1' && target_unit == '2')
        return celsius_to_fahrenheit(input_value);
    if (source_unit == '2' && target_unit == '1')
        return fahrenheit_to_celsius(input_value);
    return input_value;
}

int main(void)
{
    char category, source_unit, target_unit;
    double input_value, result_value;

    printf("Simple Unit Converter\n");

    while (1)
    {
        printf("\nChoose category:\n");
        printf("1) Length  2) Weight  3) Temperature  0) Exit\n> ");
        if (scanf(" %c", &category) != 1)
            break;
        if (category == '0')
            break;

        if (category == '1')
        {
            printf("From: 1) Meters  2) Kilometres  3) Miles\n> ");
            scanf(" %c", &source_unit);
            printf("To:   1) Meters  2) Kilometres  3) Miles\n> ");
            scanf(" %c", &target_unit);
            printf("Enter value: ");
            scanf("%lf", &input_value);

            result_value = convert_length(source_unit, target_unit, input_value);
            print_length_result(source_unit, target_unit, input_value, result_value);
        }
        else if (category == '2')
        {
            printf("From: 1) Kilograms  2) Pounds\n> ");
            scanf(" %c", &source_unit);
            printf("To:   1) Kilograms  2) Pounds\n> ");
            scanf(" %c", &target_unit);
            printf("Enter value: ");
            scanf("%lf", &input_value);

            result_value = convert_weight(source_unit, target_unit, input_value);
            print_weight_result(source_unit, target_unit, input_value, result_value);
        }
        else if (category == '3')
        {
            printf("From: 1) Celsius  2) Fahrenheit\n> ");
            scanf(" %c", &source_unit);
            printf("To:   1) Celsius  2) Fahrenheit\n> ");
            scanf(" %c", &target_unit);
            printf("Enter value: ");
            scanf("%lf", &input_value);

            result_value = convert_temp(source_unit, target_unit, input_value);
            print_temp_result(source_unit, target_unit, input_value, result_value);
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    printf("Goodbye!\n");
    return 0;
}
