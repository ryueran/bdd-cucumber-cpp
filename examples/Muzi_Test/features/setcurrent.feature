# language: en
Feature: Set current
  In order to avoid silly mistakes
  As a math idiot 
  I want to be told the sum of two numbers

  Scenario Outline: Add two numbers
    Given I have set <input> for the current
    When The current has been set
    Then The result is <output>

  Examples:
    | input | output |
    | 20    | 20     |
