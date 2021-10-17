from pytube import YouTube

print("Enter the url of the video:")

url = input()

yt = YouTube(url)

# Youtube video title
print(f"\n*********************\nTitle:  {yt.title}\n*********************")

# # video thumbnail
# print(yt.thumbnail_url)

sl = 0
record_res = {}



# all stream resolutions
print(f"\nAvailable resolutions for the video {yt.title}")
for stream in yt.streams:
    if stream.resolution not in record_res.values():
        sl+=1
        print(f"{sl} -- {stream.resolution}")
        record_res[sl] = stream.resolution


Selected_resol = int(input("Enter the no for which the resolution you want to download: "))


# downloading the video in desired resoultion
down_vid = yt.streams.filter(res=record_res[Selected_resol])
down_vid = yt.streams.filter(progressive=True)
down_vid.first().download(output_path="S:\VIDEO SONGS")

print("\nDownload Completed...")