#include <AudioSystem.h>

AudioSystem::AudioSystem() {
  // _ptrControls = ptrControls;
}

MusicNode* AudioSystem::getMusicNode(int index) {
  return (_ptrSynthMusicNodes[index]);
}

int AudioSystem::getNumberOfMusicNodes() {
  return NUMBER_OF_MUSIC_NODES;
}

void AudioSystem::activateSampler() {
  for (int i = 0; i < NUMBER_OF_MUSIC_NODES; i++)
  {
    // _ptrActiveMusicNodes[i]->deactivate();
    // _ptrActiveMusicNodes[i] = _ptrSamplerMusicNodes[i];
    // _ptrActiveMusicNodes[i]->activate();
  }
  
}

void AudioSystem::activateSynth() {
  for (int i = 0; i < NUMBER_OF_MUSIC_NODES; i++)
  {
    // _ptrActiveMusicNodes[i]->deactivate();
    // _ptrActiveMusicNodes[i] = _ptrSynthMusicNodes[i];
    // _ptrActiveMusicNodes[i]->activate();
  }
  
}