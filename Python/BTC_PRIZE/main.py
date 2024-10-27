import requests as r
import sys
# command line argument input format:
# python main.py {amount of btc}
def main():
    try:
        while True:
            if len(sys.argv) == 1:
                print('Missing command-line argument')
                break
            elif len(sys.argv) == 2:
                quantity = sys.argv[1]
                quantity = float(quantity)
                data = r.get('https://api.coindesk.com/v1/bpi/currentprice.json').json()
                price = float(data['bpi']['USD']['rate_float'])
                amount = price*quantity
                print(f"${amount:,.4f}")
                break           
    except:
        print("Command-line argument is not a number")
if __name__ == '__main__':
    main()