const express = require('express');
const mongoose = require('mongoose');

const app = express();
const PORT = process.env.PORT || 3000;

// Connect to MongoDB
mongoose.connect(process.env.MONGODB_URI, {
  useNewUrlParser: true,
  useUnifiedTopology: true,
});

// Create a Vote model
const Vote = mongoose.model('Vote', { candidate: String });

// Serve static files
app.use(express.static('public'));

// Handle votes
app.post('/vote/:candidate', async (req, res) => {
  const { candidate } = req.params;

  // Save the vote to the database
  await Vote.create({ candidate });

  res.send('Vote recorded successfully!');
});

// Get total votes
app.get('/totalVotes', async (req, res) => {
  const totalVotes = await Vote.countDocuments();
  res.json({ totalVotes });
});

app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
