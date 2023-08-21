import urllib.request

def main():
    url = "https://www.google.com"  # Replace with the URL of the webpage you want to grab

    try:
        with urllib.request.urlopen(url) as response:
            html_content = response.read().decode("utf-8")

            with open("output.html", "w", encoding="utf-8") as output_file:
                output_file.write(html_content)

            print("HTML content grabbed and saved to 'output.html'")
    except urllib.error.URLError as e:
        print("Error:", e)

if __name__ == "__main__":
    main()