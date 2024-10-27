# BTC Price Checker

A simple CLI tool to check the current value of a specified amount of Bitcoin (BTC) in USD. This tool fetches real-time BTC price data from the CoinDesk API and calculates the equivalent value of a given BTC quantity.

## Features
- Fetches the latest BTC to USD exchange rate from the CoinDesk API.
- Calculates and displays the USD value for a specified amount of BTC.

## Usage
To check the value of a specific amount of BTC, use the following command:
```bash
    python main.py {quantity_of_btc}
    # Example
    python main.py 0.05
    # Output
    $3,381.3131