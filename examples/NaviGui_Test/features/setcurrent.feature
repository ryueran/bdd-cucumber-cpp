Feature: Calculator UI Test
  Scenario: 用户点击按钮，界面显示 JSON 里的数据
    Given 应用已启动
    When 用户点击 "显示数据" 按钮
    Then "TextField1" 应该显示 "123.45"
    And "TextField2" 应该显示 "678.90"
