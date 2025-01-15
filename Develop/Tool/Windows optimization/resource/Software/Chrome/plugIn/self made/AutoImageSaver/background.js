chrome.runtime.onMessage.addListener((request, sender, sendResponse) => {
  if (request.action === "downloadImage") {
    chrome.downloads.download({
      url: request.url,
      filename: `catimelogo/${generateFilename(request.url)}`,
      conflictAction: 'uniquify',
      saveAs: false
    }, (downloadId) => {
      if (downloadId) {
        console.log(`下载已开始，ID: ${downloadId}`);
      } else {
        console.error('下载失败:', chrome.runtime.lastError);
      }
    });
  }
});

function generateFilename(url) {
  const urlObj = new URL(url);
  const pathname = urlObj.pathname;
  const filename = pathname.substring(pathname.lastIndexOf('/') + 1);
  return filename || `image_${Date.now()}.png`;
}