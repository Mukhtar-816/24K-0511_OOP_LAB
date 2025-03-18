#include <iostream>
using namespace std;

class MediaFile {
protected:
    string filePath;
    double fileSize;

public:
    MediaFile(string path, double size) : filePath(path), fileSize(size) {}

    virtual void play() = 0;
    virtual void stop() = 0;

    virtual void displayInfo() {
        cout << "File: " << filePath << " | Size: " << fileSize << " MB" << endl;
    }

    virtual ~MediaFile() {}
};

class VisualMedia : virtual public MediaFile {
protected:
    string resolution;

public:
    VisualMedia(string path, double size, string res) 
        : MediaFile(path, size), resolution(res) {}

    void displayInfo() override {
        MediaFile::displayInfo();
        cout << "Resolution: " << resolution << endl;
    }
};

class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;

public:
    AudioMedia(string path, double size, int rate) 
        : MediaFile(path, size), sampleRate(rate) {}

    void displayInfo() override {
        MediaFile::displayInfo();
        cout << "Sample Rate: " << sampleRate << " Hz" << endl;
    }
};

class ImageFile : public VisualMedia {
public:
    ImageFile(string path, double size, string res) 
        : MediaFile(path, size), VisualMedia(path, size, res) {}

    void play() override {
        cout << "Displaying image: " << filePath << endl;
    }

    void stop() override {
        cout << "Closing image: " << filePath << endl;
    }

    void displayInfo() override {
        cout << "[Image] ";
        VisualMedia::displayInfo();
    }
};

class AudioFile : public AudioMedia {
public:
    AudioFile(string path, double size, int rate) 
        : MediaFile(path, size), AudioMedia(path, size, rate) {}

    void play() override {
        cout << "Playing audio: " << filePath << endl;
    }

    void stop() override {
        cout << "Stopping audio: " << filePath << endl;
    }

    void displayInfo() override {
        cout << "[Audio] ";
        AudioMedia::displayInfo();
    }
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string path, double size, string res, int rate) 
        : MediaFile(path, size), VisualMedia(path, size, res), AudioMedia(path, size, rate) {}

    void play() override {
        cout << "Playing video: " << filePath << endl;
    }

    void stop() override {
        cout << "Stopping video: " << filePath << endl;
    }

    void displayInfo() override {
        cout << "[Video] ";
        VisualMedia::displayInfo();
        cout << "Sample Rate: " << sampleRate << " Hz" << endl;
    }
};

int main() {
    ImageFile img("picture.jpg", 2.5, "1920x1080");
    AudioFile audio("song.mp3", 5.0, 44100);
    VideoFile video("movie.mp4", 700, "4K", 48000);

    MediaFile* files[] = {&img, &audio, &video};

    for (auto file : files) {
        file->displayInfo();
        file->play();
        file->stop();
        cout << endl;
    }

    return 0;
}
