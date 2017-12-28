#!/bin/sh

eval "$(ssh-agent -s)"
ssh-add ~/.ssh/suokunGithub
ssh-add -l
ssh -T git@github.com

