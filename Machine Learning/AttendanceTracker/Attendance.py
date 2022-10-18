import cv2
import numpy as np
import face_recognition
import streamlit as st
import os
from datetime import datetime

st.title("Attendance Tracking System")
run = st.checkbox('Mark Attendance')
FRAME_WINDOW = st.image([])

path = 'images'
images = []
personNamesList = []
myList = os.listdir(path)
for currImg in myList:
    currentImg = cv2.imread(f'{path}/{currImg}')
    images.append(currentImg)
    personNamesList.append(os.path.splitext(currImg)[0])


def faceEncodings(images):
    encodeList = []
    for img in images:
        img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        encodes = face_recognition.face_encodings(img)[0]
        encodeList.append(encodes)
    return encodeList


def attendance(name):
    with open('Attendance.csv', 'r+') as f:
        myDataList = f.readlines()
        NameList = []
        for line in myDataList:
            entry = line.split(',')
            NameList.append(entry[0])
        if name not in NameList:
            time_now = datetime.now()
            timeString = time_now.strftime('%H:%M:%S')
            dateString = time_now.strftime('%d/%m/%Y')
            f.writelines(f'\n{name},{timeString},{dateString}')


encodeListKnown = faceEncodings(images)
print('All Encodings Complete!!!')

cap = cv2.VideoCapture(0)


while run:
    ret, frame = cap.read()
    frame=cv2.cvtColor(frame,cv2.COLOR_BGR2RGB)
    faces = cv2.resize(frame, (0, 0), None, 0.25, 0.25)
    faces = cv2.cvtColor(faces, cv2.COLOR_BGR2RGB)

    facesCurrentFrame = face_recognition.face_locations(faces)
    CurrentFrameEncodes = face_recognition.face_encodings(faces, facesCurrentFrame)

    for encodeFace, faceLoc in zip(CurrentFrameEncodes, facesCurrentFrame):
        matches = face_recognition.compare_faces(encodeListKnown, encodeFace)
        faceDis = face_recognition.face_distance(encodeListKnown, encodeFace)
        matchIndex = np.argmin(faceDis)

        if matches[matchIndex]:
            name = personNamesList[matchIndex].upper()
            y1, x2, y2, x1 = faceLoc
            y1, x2, y2, x1 = y1 * 4, x2 * 4, y2 * 4, x1 * 4
            cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
            cv2.rectangle(frame, (x1, y2 - 35), (x2, y2), (0, 255, 0), cv2.FILLED)
            cv2.putText(frame, name, (x1 + 6, y2 - 6), cv2.FONT_HERSHEY_COMPLEX, 1, (255, 255, 255), 2)
            attendance(name)
    FRAME_WINDOW.image(frame)
    cv2.imshow('Camera', frame)
    if cv2.waitKey(20) == 13:
        break   
else:
    st.write('Stopped')
cap.release()
cv2.destroyAllWindows()