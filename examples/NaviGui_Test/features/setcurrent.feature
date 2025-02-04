Feature: Calculator UI Test
  Scenario: User clicks button，UI shows data from json
    Given Application started
    When User clicks "read json" button
    Then "TextField1" should display "123.45"
    And "TextField2" should display "678.90"
