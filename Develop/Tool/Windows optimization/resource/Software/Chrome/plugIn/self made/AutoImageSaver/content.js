// 功能1：自动保存PNG和JPG格式的图片，排除名称包含"splash"或"favicon"的图片
function saveImages() {
  const images = document.querySelectorAll('img');
  images.forEach(img => {
    const src = img.src;
    if (src && !img.dataset.saved && isValidImage(src) && !isExcludedImage(src)) {
      chrome.runtime.sendMessage({ action: "downloadImage", url: src });
      img.dataset.saved = 'true'; // 标记已保存，避免重复下载
    }
  });
}

function isValidImage(url) {
  return (/\.(jpeg|jpg|png)(\?.*)?$/i).test(url);
}

function isExcludedImage(url) {
  const filename = getFilenameFromUrl(url).toLowerCase();
  return filename.includes('splash') || filename.includes('favicon');
}

function getFilenameFromUrl(url) {
  try {
    const urlObj = new URL(url);
    const pathname = urlObj.pathname;
    return pathname.substring(pathname.lastIndexOf('/') + 1);
  } catch (error) {
    console.error('无效的URL:', url);
    return '';
  }
}

// 功能2：自动点击指定的“重新生成”按钮
function clickRegenerateButton() {
  // 定义“重新生成”按钮的选择器
  // 基于aria-label和类名进行定位
  const regenerateButtons = document.querySelectorAll('div[aria-label="重新生成"] button.regenerate-response-button');

  regenerateButtons.forEach(button => {
    // 检查是否已经点击过
    if (button.dataset.clicked) return;

    // 点击按钮
    button.click();
    button.dataset.clicked = 'true'; // 标记为已点击，避免重复点击
    console.log('“重新生成”按钮已被点击。');
  });
}

// 初次运行时保存已存在的图片并点击“重新生成”按钮
saveImages();
clickRegenerateButton();

// 监听DOM变化，保存新添加的图片并点击“重新生成”按钮
const observer = new MutationObserver((mutations) => {
  mutations.forEach(() => {
    saveImages();
    clickRegenerateButton();
  });
});

observer.observe(document.body, { childList: true, subtree: true });