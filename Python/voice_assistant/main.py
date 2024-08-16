import speech_recognition as sr
from gtts import gTTS
from PIL import ImageGrab
import winsound
from pydub import AudioSegment


def listen_for_command():
    r = sr.Recognizer()

    with sr.Microphone() as source:
        print("Listening for commands...")
        r.adjust_for_ambient_noise(source)
        audio = r.listen(source)

    try:
        com = r.recognize_google(audio)
        print("You said ", com)
        return com.lower()
    except sr.UnknownValueError:
        print("Could not understand audio. Please try again")
        return None
    except sr.RequestError:
        print("Unable to access the Google Speech Recognition API")
        return None


def assistant_response(text):
    print(text)
    tts = gTTS(text=text, lang="en")
    tts.save("welcome.mp3")
    sound = AudioSegment.from_mp3("welcome.mp3")
    sound.export("response.wav", format="wav")
    winsound.PlaySound("response.wav", winsound.SND_FILENAME)


def print_tasks(task_list):
    for index, key in enumerate(task_list):
        print(f'{index+1}. {key}')


if __name__ == "__main__":
    tasks = []
    while True:
        command = listen_for_command()
        if command:
            if command == "ok google":
                assistant_response("Hello, how can I help you?")
            elif command == "take a screenshot":
                assistant_response("I have taken a screenshot")
                screenshot = ImageGrab.grab()
                screenshot.save("screenshot.png")
                screenshot.close()
            elif command == "add a task":
                assistant_response("What task would you like to add")
                task = listen_for_command()
                if task is not None:
                    tasks.append(task)
                    assistant_response("I have added the task '{}' successfully".format(task))
            elif command == "print my tasks":
                print_tasks(tasks)
                assistant_response("I have printed a list of tasks")
            elif command == "quit":
                assistant_response("Goodbye")
                break


