import requests
from bs4 import BeautifulSoup

def scrape_and_save_text(url, filename="output.txt"):
    # Send a GET request
    response = requests.get(url)
    response.raise_for_status()  # Check for request errors

    # Parse HTML content
    soup = BeautifulSoup(response.text, 'html.parser')

    # Extract all visible text
    text = soup.get_text(separator="\n", strip=True)

    # Save the text to a file
    with open(filename, "w", encoding="utf-8") as file:
        file.write(text)

    print(f"Text saved to {filename}")

# Example usage
url = "https://www.gutenberg.org/cache/epub/100/pg100.txt"  # Replace with your URL
scrape_and_save_text(url, "shakespeare.txt")