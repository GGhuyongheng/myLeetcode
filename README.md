# myLeetcode
# 配置git
ssh-keygen.exe -t rsa
ssh -T git@github.com
如果需要代理则配置 git config --global http.proxy http://127.0.0.1:7890
git config --global user.name hyh
git config --global user.email "hyhgodlk@gmail.com"

# 上传代码
git remote add orgin https://github.com/GGhuyongheng/myLeetcode.git
git push -u orgin master
git pull
